import re

import os

URL_PATTERN = re.compile("\\[[^\\]]+\\]\\(([^\\)]+)\\)")

for filename in os.listdir("../"):
    if filename.endswith(".md"):
        file_ = open(os.path.join("../", filename), "r")
        content = file_.read()
        file_.close()
        
        index = 0
        while True:
            match = URL_PATTERN.search(content, index)
            if not match:
                break
            
            if match.group(1).lower() == "function-reference/README.md".lower():
                content = content[:match.start(1)] + "https://github.com/Zuzu-Typ/PyGLM/blob/master/wiki/function-reference/README.md" + content[match.end(1):]
            else:
                content = content[:match.start(1)] + match.group(1).replace(".md", "") + content[match.end(1):]
            
            index = match.end()
            
        file_ = open(filename, "w")
        file_.write(content)
        file_.close()