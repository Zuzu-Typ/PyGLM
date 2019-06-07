# PyGLM  
## OpenGL Mathematics \(GLM\) library for Python  
**GLSL \+ Optional features \+ Python = PyGLM**  
**A mathematics library for graphics programming\.**  
  
**PyGLM** is a Python extension written in **C\+\+**\.   
By using [GLM by G\-Truc](https://glm.g-truc.net) under the hood, it manages to bring **glm's features** to Python\.    
Currently, some features haven't yet found their way into PyGLM and some never will \(such as unstable extensions\)\.  
If you encounter any issues or want to request a feature, please create an issue on the [issue tracker](https://github.com/Zuzu-Typ/PyGLM/issues)\.  
  
## Tiny Documentation  
### Why PyGLM?  
Besides the obvious \- being mostly compatible with **GLM** \- PyGLM offers a variety of features for **vector** and **matrix manipulation**\.  
It has a lot of possible use cases, including **3D\-Graphics** \(OpenGL, DirectX, \.\.\.\), **Physics** and more\.  
  
At the same time, it has **great performance**, being between **2x and 15x as fast as numpy\!**  
\(*depending on the individual function*\)  
### Installation  
**PyGLM** supports **Windows**, **Linux**, **MacOS** and other operating systems with either x86 \(**32\-bit**\) or x64 \(**64\-bit**\) architecture,   
running **Python 3**\.5 or higher\. \(Prior versions of Python \- such as Python 2 \- were supported up to PyGLM version 0\.4\.8b1\)  
  
It can be installed from the [PyPI](https://pypi.python.org/pypi/PyGLM) using [pip](https://pip.pypa.io/en/stable/):  

    pip install pyglm
  
And finally imported and used:  

    import glm
  
### Using PyGLM  
PyGLM's syntax is very similar to the original GLM's syntax\.  
There is no need to import anything but **glm**, as it already contains the entire package\.  
#### License requirements  
Please make sure to **include the license for GLM** in your project when you use PyGLM\!  
\(this also includes **binary distributions**, e\.g\. \*\.exe\)  
  
You can do so by copying either the `COPYING` or `GLM_LICENSE` file \(or their contents\) to your project\.  
#### Differences to glm  
Instead of using double colons \(**::**\) for namespaces, periods \(**\.**\) are used, so  
`glm::vec2` becomes `glm.vec2`\.  
  
PyGLM is compatible to numpy, meaning you can e\.g\. convert a glm matrix to a numpy array and vice versa\.  
PyGLM is also capable of interpreting iterables \(such as tuples\) as vectors, so e\.g\. the following equasion is possible:  

    result = glm.vec2(1) * (2, 3)
  
  
PyGLM doesn't support precision qualifiers\. All types use the default precision \(`packed_highp`\)\.  
  
If a glm function normally accepts `float` and `double` arguments, the higher precision \(`double`\) is used\.  
  
There is no way to set preprocessor definitions \(macros\)\.  
If \- for example \- you need to use the left handed coordinate system, you have to use **\*LH**, so  
`glm.perspective` becomes `glm.perspectiveLH`\.  
  
All types are initialized by default to avoid memory access violations\.  
\(i\.e\. the macro `GLM_FORCE_CTOR_INIT` is defined\)  
  
In case you need the size of a PyGLM datatype, you can use   

    glm.sizeof(<type>)
  
  
The function `glm.identity` requires a matrix type as it's argument\.  
  
The function `glm.frexp(x, exp)` returns a tuple `(m, e)`, if the input arguments are numerical\.  
This function may issue a `UserWarning`\. You can silence this warning using `glm.silence(1)`\.  
  
The function `glm.value_ptr(x)` returns a ctypes pointer of the respective type\.  
I\.e\. if the datatype of `x` is `float`, then a `c_float` pointer will be returned\.  
Likewise the reverse\-functions \(such as `make_vec2(ptr)`\) will take a ctypes pointer as their argument  
and return \(in this case\) a 2 component vector of the pointers underlying type\.  
  
`glm.silence(ID)` can be used to silence specific warnings\.  
Supplying an id of 0 will silence all warnings\.  
  
There is currently no documentation for PyGLM\.  
Please refer to the source \(in Python: **\*\.\_\_doc\_\_**\) and [GLM manuals](https://github.com/g-truc/glm/blob/master/manual.md), [references](https://glm.g-truc.net/0.9.9/api/modules.html) and [tutorials](https://learnopengl.com/)\.  
  
#### Unsupported functions  
Aside from the unstable extensions,  
PyGLM doesn't support the following extensions and methods, due to compatibility issues:  
The `GLM_GTC_bitfield` extension,  
`glm::log2` from GLM\_GTC\_integer\.  
`glm::packUnorm` and `glm::packSnorm` from GLM\_GTC\_packing\.  
  
### Example  

    
    >>> import glm
    >>> v = glm.vec3()
    >>> v.x = 7
    >>> print(v.xxy)
    vec3(            7,            7,            0 )
    
    >>> m = glm.mat4()
    >>> print(m)
    [            1 |            0 |            0 |            0 ]
    [            0 |            1 |            0 |            0 ]
    [            0 |            0 |            1 |            0 ]
    [            0 |            0 |            0 |            1 ]
    
    >>> v = glm.vec4(1, 2, 3, 4)
    >>> print(v + (8, 7, 6, 5))
    vec4(            9,            9,            9,            9 )
