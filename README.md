[//]: # (generated using SlashBack 0.2.0)

# PyGLM  
## OpenGL Mathematics \(GLM\) library for Python  
**GLSL \+ Optional features \+ Python = PyGLM**  
**A mathematics library for graphics programming\.**  
  
**PyGLM** is a Python extension written in **C\+\+**\.   
By using [GLM by G\-Truc](https://glm.g-truc.net) under the hood, it manages to bring **glm's features** to Python\.&nbsp;&nbsp;  
Some features are unsupported \(such as most unstable extensions\)\.  
If you encounter any issues or want to request a feature, please create an issue on the [issue tracker](https://github.com/Zuzu-Typ/PyGLM/issues)\.  
  
**For a complete reference of the types and functions, please take a look at the [wiki](https://github.com/Zuzu-Typ/PyGLM/wiki)**\.  
  
## Tiny Documentation  
### Why PyGLM?  
Besides the obvious \- being mostly compatible with **GLM** \- PyGLM offers a variety of features for **vector** and **matrix manipulation**\.  
It has a lot of possible use cases, including **3D\-Graphics** \(OpenGL, DirectX, \.\.\.\), **Physics** and more\.  
  
At the same time, it has **great performance**, being between **1\.5x and 100x as fast as numpy\!** \(see [end of page](#speed-comparison-to-numpy)\)  
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
  
For more information, take a look at the [wiki](https://github.com/Zuzu-Typ/PyGLM/wiki)\.  
#### License requirements  
Please make sure to **include the license for GLM** in your project when you use PyGLM\!  
\(this is especially relevant for **binary distributions**, e\.g\. \*\.exe\)  
  
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
  
  
### FAQ  
#### How to pass the matrices generated by PyGLM to OpenGL functions?  
You will find an overview on the \[[Passing data to external libs](wiki/Passing-data-to-external-libs.md)\] page\.  
  
#### Types and functions are not available after installing from the PyPI using ``` pip install glm ```  
Most likely you've installed [glm](https://pypi.org/project/glm/), a JSON parser and not [PyGLM](https://pypi.org/project/PyGLM/) \(or a very early version of PyGLM\)\.&nbsp;&nbsp;  
The correct install command is:  
``` 
pip install PyGLM
 ```  
  
#### Why is *&lt;experimental extension name here&gt;* not supported?  
I prefer not to add too many experimental extensions to PyGLM, especially as they might change or be removed in the future and it is simply too much effort for me to keep up with all that\.&nbsp;&nbsp;  
If you **need a specific experimental extension**, feel free to **submit a feature request** on the [issue tracker](https://github.com/Zuzu-Typ/PyGLM/issues)\.&nbsp;&nbsp;  
I try adding them on a one\-by\-one basis\.  
  
#### Why are Python versions prior to 3\.5 no longer supported?  
Starting with version [0\.5\.0b1](https://github.com/Zuzu-Typ/PyGLM/releases/tag/0.5.0b1) I decided to use C\+\+ to build PyGLM, using [glm](https://glm.g-truc.net/) under the hood \- which requires C\+\+ 11 or upwards\.&nbsp;&nbsp;  
Only Python versions 3\.5\+ support C\+\+ 11, thus I was forced to stop supporting older versions\.&nbsp;&nbsp;  
The last version to support Python 2 and &lt;3\.5 is [0\.4\.8b1](https://github.com/Zuzu-Typ/PyGLM/releases/tag/0.4.8b1)\.  
  
### Short example  
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
The following chart shows the results of running "PyGLM vs NumPy.py".
Each of the instructions were ran for 1 second to get more accurate results.

+----------------------------------------+------------+------------+-----------+
| Description                            | PyGLM runs | NumPy runs | ratio     |
+----------------------------------------+------------+------------+-----------+
| 3 component vector creation            |    3.555M  |    2.410M  |     1.47x |
+----------------------------------------+------------+------------+-----------+
| 3 component vector creation with       |            |            |           |
| custom components                      |    3.293M  |  716,951   |     4.59x |
+----------------------------------------+------------+------------+-----------+
| dot product                            |    4.334M  |  900,117   |     4.82x |
+----------------------------------------+------------+------------+-----------+
| cross product                          |    4.143M  |   42,090   |    98.45x |
+----------------------------------------+------------+------------+-----------+
| L2-Norm of 3 component vector          |    4.685M  |  278,776   |    16.81x |
+----------------------------------------+------------+------------+-----------+
| 4x4 matrix creation                    |    3.982M  |    2.387M  |     1.67x |
+----------------------------------------+------------+------------+-----------+
| 4x4 identity matrix creation           |    4.077M  |  453,426   |     8.99x |
+----------------------------------------+------------+------------+-----------+
| 4x4 matrix transposition               |    3.960M  |    1.254M  |     3.16x |
+----------------------------------------+------------+------------+-----------+
| 4x4 matrix multiplicative inverse      |    3.727M  |   36,977   |   100.81x |
+----------------------------------------+------------+------------+-----------+
| 3 component vector addition            |    3.585M  |    1.432M  |     2.50x |
+----------------------------------------+------------+------------+-----------+
| 4x4 matrix multiplication              |    3.096M  |    1.349M  |     2.29x |
+----------------------------------------+------------+------------+-----------+
| 4x4 matrix - 4 component vector        |            |            |           |
| multiplication                         |    3.278M  |  681,509   |     4.81x |
+----------------------------------------+------------+------------+-----------+
 ```