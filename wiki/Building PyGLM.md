[//]: # (generated using SlashBack 0.2.0)

This page is intended for those, who want to build a specific subversion of PyGLM or want to specify different build options\.  
If that's not you, then you should find the latest release with binary distributions over [here](https://github.com/Zuzu-Typ/PyGLM/releases/latest) or over on [PyPI](https://pypi.org/project/PyGLM/)\.  
  
  
##  Setting up the environment  
In order to build PyGLM, you're going to need a working C\+\+ development environment\.&nbsp;&nbsp;  
Although compilation should work with any C\+\+ compiler, the only ones officially supported are&nbsp;&nbsp;  
  
*  [MSVC](https://en.wikipedia.org/wiki/Microsoft_Visual_C%2B%2B) \(Microsoft Visual C\+\+\) for Windows  
&nbsp;&nbsp;Click here to download the [build tools](https://visualstudio.microsoft.com/thank-you-downloading-visual-studio/?sku=BuildTools&rel=16)  
*  [GCC](https://gcc.gnu.org/) \(GNU Compiler Collection\) mostly for Linux   
&nbsp;&nbsp;``` sudo apt install gcc ``` \(probably\)  
*  [Clang](https://clang.llvm.org/get_started.html) default Mac OS X compiler   
&nbsp;&nbsp;Should already be [installed](https://www.ics.uci.edu/~pattis/common/handouts/macclion/clang.html)\.  
  
That should be all there is to it\.  
  
##  Build options   
If you want to change some build options or make a completely custom build, go ahead and clone PyGLM\.  
  
There are three different predefined build options that you can choose from inside of [build\_options\.h](https://github.com/Zuzu-Typ/PyGLM/blob/master/build_options.h)\.&nbsp;&nbsp;  
One of the lines should be&nbsp;&nbsp;  
``` 
#define PyGLM_BUILD PyGLM_DEFAULT
 ```   
You can replace ``` PyGLM_DEFAULT ``` by one of the following options:&nbsp;&nbsp;  
  
*  ``` PyGLM_FAST ``` \- No support for using iterables / buffers instead of PyGLM types&nbsp;&nbsp;  
*  ``` PyGLM_NO_FUNCTIONS ``` \- Only build the types&nbsp;&nbsp;  
*  ``` PYGLM_MINIMAL ``` \- Combines ``` PyGLM_FAST ``` and ``` PyGLM_NO_FUNCTIONS ```  
  
Another option ``` PyGLM_SLIM ``` was planned, which was supposed to only build the float types, to decrease the file size, though demand seems to be low\.  
  
## Starting the build process  
To build PyGLM, simply run&nbsp;&nbsp;  
``` 
python setup.py install
 ```  
\(you do need Python 3\.5 or higher\)