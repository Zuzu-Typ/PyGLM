
# License (zlib/libpng):

#############################################
#                                            #
#  Copyright (c) 2019 Zuzu_Typ               #
#--------------------------------------------#
#  This software is provided 'as-is',        #
#  without any express or implied warranty.  #
#  In no event will the authors be held      #
#  liable for any damages arising from the   #
#  use of this software.                     #
#                                             #
#  Permission is granted to anyone to use     #
#  this software for any purpose, including   #
#  commercial applications, and to alter it   #
##  and redistribute it freely, subject to     #
##  the following restrictions:                #
##                                             #
##  1. The origin of this software must not    #
##     be misrepresented; you must not claim   #
##     that you wrote the original software.   #
##     If you use this software in a product,  #
##     an acknowledgment in the product        #
##     documentation would be appreciated but  #
##     is not required.                        #
##                                             #
##  2. Altered source versions must be         #
# #     plainly marked as such, and must not    #
# #     be misrepresented as being the          #
# #     original software.                      #
# #                                             #
# #  3. This notice may not be removed or       #
###     altered from any source distribution.   #
  ##############################################

from builtins import open as builtins_open

import sys, os, traceback, string

__version__ = "0.2.0"

__welcome__ = f"""\
SlashBack v{__version__} by Zuzu_Typ"""

__doc__ = """\
A little editor for my own markup language
called SlashBack ( \\SB\\ )."""

__usage__ = """\
Usage:
SlashBack.py <input_file(s)>"""

class TextConfig:
    NO_LIST         = 0
    ORDERED_LIST    = 1
    UNORDERED_LIST  = 2

    NO_TASK         = 0
    CHECKED_TASK    = 1
    UNCHECKED_TASK  = 2
    
    bold            = False
    italic          = False
    strikethrough   = False
    underline       = False
    quote           = False
    table           = False
    separator       = False
    raw             = False
    ignore          = False
    code            = None
    image           = None
    url             = None
    mention         = None
    reference       = None
    comment         = None
    list            = NO_LIST
    task            = NO_TASK
    header          = 0
    index           = 1
    indent          = 1
    list_indices    = {} # only for ordered lists
    
    def __init__(self, other_config = None):
        if other_config:
            self.bold           = other_config.bold
            self.italic         = other_config.italic
            self.strikethrough  = other_config.strikethrough
            self.underline      = other_config.underline
            self.quote          = other_config.quote
            self.table          = other_config.table
            self.separator      = other_config.separator
            self.raw            = other_config.raw
            self.ignore         = other_config.ignore
            self.code           = other_config.code
            self.image          = other_config.image
            self.url            = other_config.url
            self.mention        = other_config.mention
            self.reference      = other_config.reference
            self.comment        = other_config.comment
            self.list           = other_config.list
            self.task           = other_config.task
            self.header         = other_config.header
            self.index          = other_config.index
            self.indent         = other_config.indent
            self.list_indices   = other_config.list_indices.copy()

    def __str__(self):
        out = set()

        if self.comment:
            out.add(f"/* {self.comment} */")
        if self.bold:
            out.add("bold")
        if self.italic:
            out.add("italic")
        if self.strikethrough:
            out.add("strikethrough")
        if self.underline:
            out.add("underline")
        if self.quote:
            out.add("quote")
        if self.table:
            out.add(f"table at {self.index}")
        if self.raw:
            out.add("<raw>")
        if self.code:
            out.add(f"code {self.code}")
        if self.image:
            out.add(f"image {self.image}")
        if self.url:
            out.add(f"url {self.url}")
        if self.mention:
            out.add(f"mention {self.mention}")
        if self.reference:
            out.add(f"reference {self.reference}")
        if self.list:
            out.add(("ordered list" if self.list == self.ORDERED_LIST else "unordered list") + f" at {self.index}")
        if self.task:
            out.add("checked task" if self.list == self.CHECKED_TASK else "unchecked task")
        if self.header:
            out.add(f"h{self.header}")
        if self.separator:
            out.add("---")

        return ", ".join(out)

    __repr__ = lambda self: self.__str__()

class Text:
    def __init__(self, text, text_config):
        self.text = text
        self.text_config = text_config

class ParsedText:
    def __init__(self, text_list):
        self.text_list = text_list

    def to_markdown(self):
        out = [f"[//]: # (generated using SlashBack {__version__})\n\n".encode()]

        current_text_config = TextConfig()

        table_signalized = True

        for text in self.text_list:
            text_string = text.text
            this_text_config = text.text_config

            if this_text_config.raw:
                out.append(text_string)
                continue

            if not this_text_config.code:
                for char in "\\`*_{}[]()#+-.!":
                    text_string = text_string.replace(char.encode(), f"\\{char}".encode())
                for char, replacement in ((b"&", b"&amp;"), (b"<", b"&lt;"), (b">", b"&gt;"), (b"~", b"&#126;"), (b"|", b"&#124;"), (b"@", b"@<!---->"), (b"`", b"&#96;")):
                    text_string = text_string.replace(char, replacement)

                if not this_text_config.table:
                    text_string = text_string.replace(b"\t", b"    ").replace(b"  ", b"&nbsp;" * 2).replace(b"\r\n", b"\n").replace(b"\r", b"\n").replace(b"\n", b"  \n")
            else:
                pass#text_string = text_string.replace(b"`", b"&#96;")

            if not table_signalized and b"\n" in text_string:
                table_signalized = True
                text_string = text_string.replace(b"\n", b"\n" + b"|".join([b"-"] * (this_text_config.index + 1)) + b"\n")

            

            if this_text_config.list and this_text_config.index != 0 and current_text_config.index != this_text_config.index:
                out.append(b"    " * (this_text_config.indent - 1) + ( f"{this_text_config.index}. ".encode() if this_text_config.list == TextConfig.ORDERED_LIST else b"* "))

            if current_text_config.table and this_text_config.table and current_text_config.index < this_text_config.index:
                out.append(b"|")

            if not current_text_config.bold and this_text_config.bold:
                out.append(b"**")

            if not current_text_config.italic and this_text_config.italic:
                out.append(b"*")

            if not current_text_config.strikethrough and this_text_config.strikethrough:
                out.append(b"~~")

            if not current_text_config.underline and this_text_config.underline:
                out.append(b"<u>")

            if not current_text_config.quote and this_text_config.quote:
                out.append(b">")

            if not current_text_config.table and this_text_config.table:
                table_signalized = False

            if not current_text_config.code and this_text_config.code:
                out.append(b"``` ")
                if isinstance(this_text_config.code, bytes):
                    out.append(this_text_config.code)

            if not current_text_config.image and this_text_config.image:
                out.append(b"![")

            if not current_text_config.url and this_text_config.url:
                out.append(b"[")

            if not current_text_config.list and this_text_config.list:
                pass

            if not current_text_config.task and this_text_config.task:
                if this_text_config.task == TextConfig.CHECKED_TASK:
                    out.append(b"- [x] ")
                else:
                    out.append(b"- [ ] ")

            if not current_text_config.header and this_text_config.header:
                out.append(b"#" * this_text_config.header + b" ")

            if not current_text_config.separator and this_text_config.separator:
                out.append(b"\n---")

            if not current_text_config.mention and this_text_config.mention:
                out.append(b"@" + this_text_config.mention)

            if not current_text_config.reference and this_text_config.reference:
                out.append(this_text_config.reference)

            if not current_text_config.comment and this_text_config.comment:
                out.append(f" [//]: # ({this_text_config.comment.decode()}) ".encode())
            
            # backward #

            if current_text_config.url and not this_text_config.url:
                out.append(f"]({current_text_config.url.decode()})".encode())

            if current_text_config.image and not this_text_config.image:
                out.append(f"]({current_text_config.image.decode()})".encode())

            if current_text_config.code and not this_text_config.code:
                out.append(b" ```")

            if current_text_config.task and not this_text_config.task:
                out.append(b"\n\n")

            if current_text_config.quote and not this_text_config.quote:
                out.append(b"\n\n")

            if current_text_config.underline and not this_text_config.underline:
                out.append(b"</u>")

            if current_text_config.strikethrough and not this_text_config.strikethrough:
                out.append(b"~~")
                
            if current_text_config.italic and not this_text_config.italic:
                out.append(b"*")
                
            if current_text_config.bold and not this_text_config.bold:
                out.append(b"**")

            if not (not current_text_config.ignore and this_text_config.ignore):
                out.append(text_string)

            current_text_config = this_text_config

        if current_text_config.url:
            out.append(f"]({current_text_config.url.decode()})".encode())

        if current_text_config.image:
            out.append(f"]({current_text_config.image.decode()})".encode())

        if current_text_config.code:
            out.append(b" ```")

        if current_text_config.quote:
            out.append(b"\n\n")

        if current_text_config.strikethrough:
            out.append(b"~~")
            
        if current_text_config.italic:
            out.append(b"*")
            
        if current_text_config.bold:
            out.append(b"**")
            
        return b"".join(out)
                

class SlashBackParserError(Exception):
    pass

class SlashBackParser:
    def __init__(self, path = None, auto_read = True):
        self.path = path
        self.read()

    def read(self):
        file_ = builtins_open(self.path, "rb")
        content = file_.read()
        file_.close()

        self.parsed_text = self.parse(content)

    def write(self, path):
        file_ = builtins_open(path, "wb")
        file_.write(self.parsed_text.to_markdown())
        file_.close()

    def parse_single(self, command, config):        
        command = command.lstrip((string.whitespace + "!#/:|+.~>_<").encode()).rstrip()

        if config.separator: config.separator   = False
        if config.reference: config.reference   = None
        if config.mention: config.mention       = None
        if config.comment: config.comment       = None
        

        if command == b"raw":
            config.raw = not config.raw
            
        elif command == b"h1":
            config.header = 0 if config.header else 1
        elif command == b"h2":
            config.header = 0 if config.header else 2
        elif command == b"h3":
            config.header = 0 if config.header else 3
        elif command == b"h4":
            config.header = 0 if config.header else 4
        elif command == b"h5":
            config.header = 0 if config.header else 5
        elif command == b"h6":
            config.header = 0 if config.header else 6

        elif command == b"b":
            config.bold = not config.bold
        elif command == b"i":
            config.italic = not config.italic

        elif command in (b"separator", b"sep"):
            config.separator = True

        elif command == b"s":
            config.strikethrough = not config.strikethrough

        elif command == b"u":
            config.underline = not config.underline

        elif command in (b"quote", b"q"):
            config.quote = not config.quote

        elif command in (b"table", b"tbl"):
            if config.list:
                raise SlashBackParserError("A table can't be created inside a list")
            config.table = not config.table
            config.index = 0

        elif command in (b"list switch", b"ls", b"sl"):
            if not config.list:
                raise SlashBackParserError("There's no list to switch here")
            config.list = config.ORDERED_LIST if config.list == config.UNORDERED_LIST else config.UNORDERED_LIST
            config.index = 0

        elif command in (b"list ordered", b"lo", b"ol"):
            if config.table:
                raise SlashBackParserError("A list can't be created inside a table")
            config.list = config.NO_LIST if config.list else config.ORDERED_LIST
            config.index = 0

        elif command in (b"list unordered", b"lu", b"ul"):
            if config.table:
                raise SlashBackParserError("A list can't be created inside a table")
            config.list = config.NO_LIST if config.list else config.UNORDERED_LIST
            config.index = 0

        elif command in (b"list", b"lo", b"ol", b"lu", b"ul"):
            if not config.list:
                raise SlashBackParseError("Unspecified list type")
            
            config.list = config.NO_LIST

            config.list_indices = {}

        elif command in (b"task checked", b"tc", b"x"):
            config.task = config.NO_TASK if config.task else config.CHECKED_TASK

        elif command in (b"task unchecked", b"tu", b"o"):
            config.task = config.NO_TASK if config.task else config.UNCHECKED_TASK

        elif command in (b"task", b"tc", b"tu", b"x", b"o"):
            if not config.task:
                raise SlashBackParseError("Unspecified task type")
            
            config.task = config.NO_TASK

        elif command in (b"image", b"img"):
            if not config.image:
                raise SlashBackParseError("Unspecified image type")

            config.image = None

        elif command == b"url": #TODO
            if not config.url:
                raise SlashBackParseError("Unspecified url link")

            config.url = None

        elif command.count(b"-") == len(command):
            if config.list:
                config.indent = command.count(b"-")
                
                for indent in config.list_indices.copy():
                    if indent > config.indent:
                        del config.list_indices[indent]
                        
                if config.list == config.ORDERED_LIST:
                    config.index = config.list_indices.get(config.indent, 1)
                    
                    config.list_indices[config.indent] = config.index + 1
                else:
                    config.index += 1
                    
            elif config.table:
                config.index += 1
            if not config.list and not config.table:
                raise SlashBackParserError(f"Unexpected \\{command.decode()}\\ token")

        else:
            space_index = command.find(b" ")
            first_command = command[:space_index] if space_index != -1 else command
            info = command[space_index:].strip() if space_index != -1 else ""

            if first_command == b"image":
                config.image = None if config.image else info

            elif first_command == b"url":
                config.url = None if config.url else info

            elif first_command == b"code":
                config.code = None if config.code else info if info else True

            elif first_command == b"mention":
                config.mention = info

            elif first_command == b"reference":
                config.reference = info

            elif first_command in (b"c", b"comment", b"ignore"):
                config.ignore = not config.ignore

            elif first_command in (b"ic", b"icomment"):
                config.comment = info

            else:
                raise SlashBackParserError(f"Unknown command \"{first_command.decode()}\"")
            
        return config

    def parse(self, text):
        if (text.count(b"\\") % 2):
            raise SlashBackParserError("The amount of backslashes isn't even")
        index = 0
        found = text.find(b"\\", index)
        second_found = text.find(b"\\", found + 1)

        out = []

        current_text = None

        current_config = TextConfig()
        
        while found != -1:
            current_command = text[found + 1 : second_found]
            
            if not current_command:
                out.append(Text(text[index : found + 1], TextConfig(current_config)))
            else:
                out.append(Text(text[index : found], TextConfig(current_config)))
                current_config = self.parse_single(current_command, current_config)
            
            index = second_found + 1
            found = text.find(b"\\", index)
            second_found = text.find(b"\\", found + 1)

            if (second_found == -1):
                raise SlashBackParserError("Error while parsing. Inconsistent amount of backslashes")
            
        out.append(Text(text[index :], TextConfig(current_config)))

        return ParsedText(out)
        
open = lambda path: SlashBackParser(path)

if __name__ == "__main__":
    print(__welcome__)
    
    has_processed_files = False
    
    if len(sys.argv) != 1:
        print("")
        for filename in sys.argv[1:]:
            if filename[0] == "-":
                print(f"Invalid option: '{filename}' (ignoring)", file=sys.stderr)
            elif not os.path.exists(filename):
                print(f"File not found: '{filename}' (ignoring)", file=sys.stderr)
            else:
                has_processed_files = True
                out_filename = os.path.splitext(filename)[0] + ".md"
                processing_string = f"Processing file {filename} and saving to {out_filename}..."
                print(processing_string, end = "")
                try:
                    sbf = open(filename)
                    sbf.write(out_filename)
                    print(f"\r{processing_string} Done.")
                except SlashBackParserError as exception:
                    print(f"\nERROR: {exception!s}", file=sys.stderr)
                except Exception as exception:
                    print("\nUNHANDLED EXCEPTION OCCURED!", file=sys.stderr)
                    traceback.print_exc()
                
    if not has_processed_files:
        print("\n" + __usage__, file=sys.stderr)
