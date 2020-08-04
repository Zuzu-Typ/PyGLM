[//]: # (generated using SlashBack 0.2.0)

# PyGLM  
## OpenGL Mathematics \(GLM\) library for Python  
**GLSL \+ Optional features \+ Python = PyGLM**  
**A mathematics library for graphics programming\.**  
  
**PyGLM** is a Python extension written in **C\+\+**\.   
By using [GLM by G\-Truc](https://glm.g-truc.net) under the hood, it manages to bring **glm's features** to Python\.&nbsp;&nbsp;  
Some features are unsupported \(such as most unstable extensions\) \- Please see [Unsupported Functions](#unsupported-functions) below\.  
If you encounter any issues or want to request a feature, please create an issue on the [issue tracker](https://github.com/Zuzu-Typ/PyGLM/issues)\.  
  
**For a \(barely\) complete reference, please take a look at the [wiki](https://github.com/Zuzu-Typ/PyGLM/wiki)**\.  
  
## Tiny Documentation  
### [FAQ](https://github.com/Zuzu-Typ/PyGLM/wiki#faq)  
### Why PyGLM?  
Besides the obvious \- being mostly compatible with **GLM** \- PyGLM offers a variety of features for **vector** and **matrix manipulation**\.  
It has a lot of possible use cases, including **3D\-Graphics** \(OpenGL, DirectX, \.\.\.\), **Physics** and more\.  
  
At the same time, it has **great performance**, being between **2x and 15x as fast as numpy\!** \(see end of page\)  
\(*depending on the individual function*\)  
### Installation  
**PyGLM** supports **Windows**, **Linux**, **MacOS** and other operating systems with either x86 \(**32\-bit**\) or x64 \(**64\-bit**\) architecture,   
running **Python 3**\.5 or higher\. \(Prior versions of Python \- such as Python 2 \- were supported up to PyGLM version 0\.4\.8b1\)  
  
It can be installed from the [PyPI](https://pypi.python.org/pypi/PyGLM) using [pip](https://pip.pypa.io/en/stable/):  
``` batch
pip install PyGLM
# please make sure to install "PyGLM" and not "glm", which is a different module
 ```  
And finally imported and used:  
``` python
import glm
 ```  
### Using PyGLM  
PyGLM's syntax is very similar to the original GLM's syntax\.  
There is no need to import anything but **glm**, as it already contains the entire package\.  
#### License requirements  
Please make sure to **include the license for GLM** in your project when you use PyGLM\!  
\(this also includes **binary distributions**, e\.g\. \*\.exe\)  
  
You can do so by copying the ``` COPYING ``` file \(or it's contents\) to your project\.  
#### Differences to glm  
Instead of using double colons \(**::**\) for namespaces, periods \(**\.**\) are used, so  
``` glm::vec2 ``` becomes ``` glm.vec2 ```\.  
  
PyGLM supports the [buffer protocol](https://docs.python.org/3/c-api/buffer.html), meaning its compitible to other objects that support the buffer protocol,  
such as ``` bytes ``` or ``` numpy.array ```   
\(for example you can convert a glm matrix to a numpy array and vice versa\)\.  
PyGLM is also capable of interpreting iterables \(such as tuples\) as vectors, so e\.g\. the following equasion is possible:  
``` python
result = glm.vec2(1) * (2, 3)
 ```  
*Note: This feature might not or only partially be available in PyGLM versions prior to 2\.0\.0*  
  
PyGLM doesn't support precision qualifiers\. All types use the default precision \(``` packed_highp ```\)\.  
  
If a glm function normally accepts ``` float ``` and ``` double ``` arguments, the higher precision \(``` double ```\) is used\.  
  
There is no way to set preprocessor definitions \(macros\)\.  
If \- for example \- you need to use the left handed coordinate system, you have to use **\*LH**, so  
``` glm.perspective ``` becomes ``` glm.perspectiveLH ```\.  
  
All types are initialized by default to avoid memory access violations\.  
\(i\.e\. the macro ``` GLM_FORCE_CTOR_INIT ``` is defined\)  
  
In case you need the size of a PyGLM datatype, you can use   
``` python
glm.sizeof(<type>)
 ```  
  
The function ``` glm.identity ``` requires a matrix type as it's argument\.  
  
The function ``` glm.frexp(x, exp) ``` returns a tuple ``` (m, e) ```, if the input arguments are numerical\.  
This function may issue a ``` UserWarning ```\. You can silence this warning using ``` glm.silence(1) ```\.  
  
The function ``` glm.value_ptr(x) ``` returns a ctypes pointer of the respective type\.  
I\.e\. if the datatype of ``` x ``` is ``` float ```, then a ``` c_float ``` pointer will be returned\.  
Likewise the reverse\-functions \(such as ``` make_vec2(ptr) ```\) will take a ctypes pointer as their argument  
and return \(in this case\) a 2 component vector of the pointers underlying type\.  
  
``` glm.silence(ID) ``` can be used to silence specific warnings\.  
Supplying an id of 0 will silence all warnings\.  
  
#### Unsupported functions  
Aside from most of the unstable extensions,  
PyGLM doesn't support the following extensions and methods, due to compatability issues:  
The ``` GLM_GTC_bitfield ``` extension,  
``` glm::log2 ``` from GLM\_GTC\_integer\.  
``` glm::packUnorm ``` and ``` glm::packSnorm ``` from GLM\_GTC\_packing\.  
  
### Example  
``` Python
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
 ```  
  
### Speed comparison to numpy  
``` 
How PyGLM's performance roughly compares to NumPy's performance:
instruction     | np speed (%)  | glm speed (%)
import          |   4.76        |  100.00
mat4()          |   9.76        |  100.00
dot(vec3, vec3) |  28.92        |  100.00
transpose(mat4) |  25.64        |  100.00
vec4 * vec4     |  27.89        |  100.00
mat4 * vec4     |  17.68        |  100.00
mat4[0]         |  49.99        |  100.00
 ```