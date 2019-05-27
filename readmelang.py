__doc__ = """
A quick-and-dirty script for converting
a README.rml file with BBCode-like syntax
to README.rst and README.md
"""

NONE = 0
TEXT = 2**0
BOLD = 2**1
ITALIC = 2**2
URL = 2**3
CODE = 2**4
LIST = 2**5
SEPARATOR = 2**6
FOOTNOTE = 2**7
HYPERLINK = 2**8
TITLE = 2**9
SUBTITLE = 2**10
SECTION1 = 2**11
SECTION2 = 2**12
SECTION3 = 2**13
INLINE_CODE = 2**14

def format_md(text):
    for char in "\\`*{}[]()#+-.!_":
        if not char in text: continue
        text = text.replace(char, "\\"+char)
    return text

def format_rst(text):
    for char in '\\!"#$%&\'()*+,-./:;<=>?@[]^_`{|}~':
        if not char in text: continue
        text = text.replace(char, "\\"+char)
    return text

class Object:
    def __init__(self, mode=TEXT):
        self.text = ""
        self.mode = mode
        self.options = {}

    def to_rst(self, to_be_inlined = True):
        text = self.text
        if not self.mode in (CODE, INLINE_CODE):
            text = format_rst(text)
        if self.mode in (NONE, TEXT):
            ind = text.rfind("\n")
            if ind == len(text)-1:
                out = text[:ind].replace("\n", "\n| ") + text[ind:]
            else:
                out = text.replace("\n", "\n| ")
            if to_be_inlined and text.strip() != "":
                return "| {}".format(out)
            return out
        if self.mode == TITLE:
            if not to_be_inlined:
                return "\n\n{1}\n{0}\n{1}".format(text,"#"*len(text))
            return "\n{1}\n{0}\n{1}".format(text,"#"*len(text))
        if self.mode == SUBTITLE:
            if not to_be_inlined:
                return "\n\n{1}\n{0}\n{1}".format(text,"*"*len(text))
            return "\n{1}\n{0}\n{1}".format(text,"*"*len(text))
        if self.mode == SECTION1:
            if not to_be_inlined:
                return "\n\n{}\n{}".format(text,"="*len(text))
            return "\n{}\n{}".format(text,"="*len(text))
        if self.mode == SECTION2:
            if not to_be_inlined:
                return "\n\n{}\n{}".format(text,"-"*len(text))
            return "\n{}\n{}".format(text,"-"*len(text))
        if self.mode == SECTION3:
            if not to_be_inlined:
                return "\n\n{}\n{}".format(text,"^"*len(text))
            return "\n{}\n{}".format(text,"^"*len(text))
        if self.mode == ITALIC:
            if to_be_inlined:
                return "| *{}*".format(text)
            return "*{}*".format(text)
        if self.mode == BOLD:
            if to_be_inlined:
                return "| **{}**".format(text)
            return "**{}**".format(text)
        if self.mode == URL:
            if to_be_inlined:
                return "| `{} <{}>`_".format(text, self.options["url"])
            return "`{} <{}>`_".format(text, self.options["url"])
        if self.mode == INLINE_CODE:
            if to_be_inlined:
                return "| :code:`{}`".format(text)
            return ":code:`{}`".format(text)
        if self.mode == CODE:
            if to_be_inlined:
                out = "\n\n::\n\n"
            else:
                out = "\n\n::\n\n"
            for line in text.split("\n"):
                if line.strip() == "":
                    out += "    \n"
                elif line.strip() != line:
                    code = line.strip()
                    s_i = line.index(code[0])
                    e_i = line.rindex(code[-1])+1
                    out += "    {}\n".format(line)
                else:
                    out += "    {}\n".format(line)
            return out + "\n "
        if self.mode == LIST:
            return "NOTIMPLEMENTED"
        if self.mode == SEPARATOR:
            return "------------"
        if self.mode == FOOTNOTE:
            return "NOTIMPLEMENTED"
        if self.mode == HYPERLINK:
            return "NOTIMPLEMENTED"

    def to_md(self):
        text = self.text
        if not self.mode in (CODE, INLINE_CODE):
            text = format_md(text)
        if self.mode in (NONE, TEXT):
            return text.replace("\n", "  \n")
        if self.mode in (TITLE,):
            return "# {}".format(text)
        if self.mode in (SUBTITLE, SECTION1):
            return "## {}".format(text)
        if self.mode == SECTION2:
            return "### {}".format(text)
        if self.mode == SECTION3:
            return "#### {}".format(text)
        if self.mode == ITALIC:
            return "*{}*".format(text)
        if self.mode == BOLD:
            return "**{}**".format(text)
        if self.mode == URL:
            return "[{}]({})".format(text, self.options["url"])
        if self.mode == INLINE_CODE:
            print(text)
            return "`{}`".format(text)
        if self.mode == CODE:
            out = "\n"
            for line in text.split("\n"):
                out += "    {}\n".format(line)
            return out
        if self.mode == SEPARATOR:
            return "***"
        return "NOTIMPLEMENTED"
        
class Main:
    def __init__(self, path):
        file_ = open(path, "r")
        self.content = file_.readlines()
        file_.close()
        self.understood_content = [Object()]
        self.understand()

    def interpret_single(self, text, index=None, char_index=None,something_other_than_code = False):
        if text in ("/","/b", "/i", "/url", "/code","/title","/subtitle", "/s1", "/s", "/s2", "/s3", "/list", "/seperator", "/footnote", "/deffootnote", "/hyperlink"):
            self.understood_content.append(Object())
            return
        if text == "b":
            self.understood_content.append(Object(BOLD))
            return
        if text == "i":
            self.understood_content.append(Object(ITALIC))
            return
        if len(text) >= 3 and text[:3] == "url":
            self.understood_content.append(Object(URL))
            if "=" in text:
                eqi = text.index("=")
                if len(text) <= eqi+1:
                    raise SyntaxError("Empty URL at line {}:{}".format(index, char_index))
                url = text[eqi+1:].strip().replace('"', "")
                self.understood_content[-1].options["url"] = url
            else:
                self.understood_content[-1].options["url"] = None
            return
        if text == "code":
            self.understood_content.append(Object(CODE if not something_other_than_code else INLINE_CODE))
            return
        if text == "title":
            self.understood_content.append(Object(TITLE))
            return
        if text == "subtitle":
            self.understood_content.append(Object(SUBTITLE))
            return
        if text in ("s1", "s"):
            self.understood_content.append(Object(SECTION1))
            return
        if text == "s2":
            self.understood_content.append(Object(SECTION2))
            return
        if text == "s3":
            self.understood_content.append(Object(SECTION3))
            return
        if text == "list":
            self.understood_content.append(Object(LIST))
            return
        if text == "separator":
            self.understood_content.append(Object(SEPARATOR))
            return
        if len(text) >= 8 and text[:8] == "footnote":
            self.understood_content.append(Object(FOOTNOTE))
            if "=" in text:
                eqi = text.index("=")
                if len(text) <= eqi+1:
                    raise SyntaxError("Empty FOOTNOTE at line {}:{}".format(index, char_index))
                txt = text[eqi+1:].strip()
                self.understood_content[-1].options["text"] = txt
            else:
                self.understood_content[-1].options["text"] = None
            return
                
        if len(text) >= 9 and text[:9] == "hyperlink":
            self.understood_content.append(Object(HYPERLINK))
            if "=" in text:
                eqi = text.index("=")
                if len(text) <= eqi+1:
                    raise SyntaxError("Empty HYPERLINK at line {}:{}".format(index, char_index))
                link = text[eqi+1:].strip().replace('"', "")
                self.understood_content[-1].options["link"] = link
            else:
                self.understood_content[-1].options["link"] = None
            return
        self.understood_content[-1].text += "[{}]".format(text)

    def understand(self):
        index = 0
        for line in self.content:
            something_other_than_code = False
            ignore = False
            interpret_mode = False
            to_be_interpreted = ""
            char_index = -1
            for char in line:
                char_index += 1
                if char == "\\":
                    if ignore:
                        if interpret_mode:
                            to_be_interpreted += char
                        else:
                            self.understood_content[-1].text += char
                        ignore = False
                        continue
                    ignore = True
                    continue
                if ignore:
                    if interpret_mode:
                        to_be_interpreted += char
                    else:
                        self.understood_content[-1].text += char
                    ignore = False
                    continue
                
                if char == "[":
                    if line[char_index+1] != "/":
                        if line.find("]", line.find("]")+1) != -1 and (char_index != 0 or line.find("]", line.find("]")+1)+1 < len(line.strip())):
                            something_other_than_code = True
                    interpret_mode = True
                    to_be_interpreted = ""
                    continue

                if char == "]":
                    interpret_mode = False
                    self.interpret_single(to_be_interpreted, index, char_index, something_other_than_code)
                    continue

                if interpret_mode:
                    to_be_interpreted += char
                else:
                    self.understood_content[-1].text += char
            index += 1

    def as_rst(self):
        out = ""
        for obj in self.understood_content:
            if not out:
                out = obj.to_rst(True)
            else:
                out += obj.to_rst(out[-1] == "\n")
        return out
    
    def as_md(self):
        out = ""
        for obj in self.understood_content:
            out += obj.to_md()
        return out
                    
main = Main("README.rml")
rst = open("README.rst","w")
rst.write(main.as_rst())
rst.close()
md = open("README.md", "w")
md.write(main.as_md())
md.close()
