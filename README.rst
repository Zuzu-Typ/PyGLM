
#####
PyGLM
#####

*********************************************
OpenGL Mathematics \(GLM\) library for Python
*********************************************
| **GLSL \+ Optional features \+ Python \= PyGLM**
| **A mathematics library for graphics programming written in C\.**
| 
| *Work in progress\.*
| 
| **PyGLM** is based on `GLM by G\-Trunc <https://glm.g-truc.net>`_ offering a lot of the original features\.  
| PyGLM is missing some features\, either because they couldn\'t be implemented properly 
| or were deemed to be of too low priority \(like glm\:\:detail\:\:**tvec1**\)\.
| If you encounter any issues or want to request a feature\, please create an issue on the `issue tracker <https://github.com/Zuzu-Typ/PyGLM/issues>`_\.
| 
| It is between 2 and 10 times as fast as numpy
| 

Tiny Documentation
==================

Why PyGLM\?
-----------
| Besides the obvious \- being compatible with **GLM** \- PyGLM offers a variety of features for **vector** and **matrix manipulation**\.
| It has a lot of possible use cases\, including **3D\-Graphics** \(OpenGL\, DirectX\, \.\.\.\)\, **Physics** and more\.
| 
| At the same time\, it has **great performance**\, being between **2x and 10x as fast as numpy\!**
| \(*depending on the individual function*\)

Installation
------------
| **PyGLM** supports **Windows**\, **Linux**\, **MacOS** and other operating systems with either x86 \(**32\-bit**\) or x64 \(**64\-bit**\) architecture\, 
| running **Python 2 or 3**
| 
| It can be installed from the `PyPI <https://pypi.python.org/pypi/PyGLM>`_ using `pip <https://pip.pypa.io/en/stable/>`_\:


::

    pip install pyglm

 
| And finally imported and used\:


::

    import glm

 

Using PyGLM
-----------
| PyGLM\'s syntax is very similar to the original GLM\'s syntax\.
| There is no need to import anything but **glm**\, as it already contains the entire package\.
| Instead of using double colons \(**\:\:**\) for namespaces\, periods \(**\.**\) are used\, so


::

    glm::detail::tvec2

 
| becomes


::

    glm.detail.tvec2

 
| You can also use the base namespace *glm*\.


::

    glm.tvec2

 
| 
| There is no way to set preprocessor definitions \(macros\)\.
| If \- for example \- you need to use the left handed coordinate system\, you have to use **\*LH**\, so


::

    glm.perspective

 
| becomes


::

    glm.perspectiveLH

 
| 
| There is currently no documentation for PyGLM\.
| Please refer to the source \(in Python\: **\*\.\_\_doc\_\_**\) and GLM manuals\, references and tutorials\.
| 

Example
-------


::

    
    >>> import glm
    >>> v = glm.vec3()
    >>> v.x = 7
    >>> print(v.xxx)
    tvec3(            7,            7,            7 )
    
    >>> m = glm.mat4()
    >>> print(m)
    tmat4x4
    [            0 |            0 |            0 |            0 ]
    [            0 |            0 |            0 |            0 ]
    [            0 |            0 |            0 |            0 ]
    [            0 |            0 |            0 |            0 ]
    
    >>> v = glm.vec4(1, 2, 3, 4)
    >>> print(v + (8, 7, 6, 5))
    tvec4(            9,            9,            9,            9 )

 