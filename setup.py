from setuptools import Extension, setup

from codecs import open

from os import path

here = path.abspath(path.dirname(__file__))

with open(path.join(here, "VERSION")) as file_:
    VERSION = file_.read().strip()

setup(
    ext_modules=[
        Extension(
            name="pyglm.glm",
            sources=["PyGLM_lib/PyGLM.cpp"],
            include_dirs=["PyGLM_lib/glm/"], 
            extra_compile_args=['-std=c++11', f'-DVERSION={VERSION}']
        ),
    ]
)
