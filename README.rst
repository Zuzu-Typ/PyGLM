
#####
PyGLM
#####

*********************************************
OpenGL Mathematics \(GLM\) library for Python
*********************************************
| **GLSL \+ Optional features \+ Python \= PyGLM**
| **A mathematics library for graphics programming\.**
| 
| *Work in progress\.*
| 
| **PyGLM** is using `GLM by G\-Truc <https://glm.g-truc.net>`_ to offer a lot of the original features\.  
| Currently\, some features haven\'t yet found their way into PyGLM and some never will \(such as unstable extensions\)\.
| If you encounter any issues or want to request a feature\, please create an issue on the `issue tracker <https://github.com/Zuzu-Typ/PyGLM/issues>`_\.
| 

Tiny Documentation
==================

Why PyGLM\?
-----------
| Besides the obvious \- being mostly compatible with **GLM** \- PyGLM offers a variety of features for **vector** and **matrix manipulation**\.
| It has a lot of possible use cases\, including **3D\-Graphics** \(OpenGL\, DirectX\, \.\.\.\)\, **Physics** and more\.
| 
| At the same time\, it has **great performance**\, being between **2x and 10x as fast as numpy\!**
| \(*depending on the individual function*\)

Installation
------------
| **PyGLM** supports **Windows**\, **Linux**\, **MacOS** and other operating systems with either x86 \(**32\-bit**\) or x64 \(**64\-bit**\) architecture\, 
| running **Python 3**\.5 or higher\. \(Prior versions of Python \- such as Python 2 \- were supported up to PyGLM version 0\.4\.8b1\)
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

Differences to glm
^^^^^^^^^^^^^^^^^^
| Instead of using double colons \(**\:\:**\) for namespaces\, periods \(**\.**\) are used\, so
| :code:`glm::vec2` becomes :code:`glm.vec2`\.
| 
| PyGLM doesn\'t support precision qualifiers\. All types use the default precision \(:code:`packed_highp`\)\.
| 
| If a glm function normally accepts :code:`float` and :code:`double` arguments\, the higher precision \(:code:`double`\) is used\.
| 
| There is no way to set preprocessor definitions \(macros\)\.
| If \- for example \- you need to use the left handed coordinate system\, you have to use **\*LH**\, so
| :code:`glm.perspective` becomes :code:`glm.perspectiveLH`\.
| 
| All types are initialized by default to avoid memory access violations\.
| \(i\.e\. the macro :code:`GLM_FORCE_CTOR_INIT` is defined\)
| 
| In case you need the size of a PyGLM datatype\, you can use 


::

    glm.sizeof(<type>)

 
| 
| The function :code:`glm.identity` requires a matrix type as it\'s argument\.
| 
| The function :code:`glm.frexp(x, exp)` returns a tuple :code:`(m, e)`\, if the input arguments are numerical\.
| This function may issue a :code:`UserWarning`\. You can silence this warning using :code:`glm.silence(1)`\.
| 
| The function :code:`glm.value_ptr(x)` returns a ctypes pointer of the respective type\.
| I\.e\. if the datatype of :code:`x` is :code:`float`\, then a :code:`c_float` pointer will be returned\.
| Likewise the reverse\-functions \(such as :code:`make_vec2(ptr)`\) will take a ctypes pointer as their argument
| and return \(in this case\) a 2 component vector of the pointers underlying type\.
| 
| :code:`glm.silence(ID)` can be used to silence specific warnings\.
| Supplying an id of 0 will silence all warnings\.
| 
| There is currently no documentation for PyGLM\.
| Please refer to the source \(in Python\: **\*\.\_\_doc\_\_**\) and GLM manuals\, references and tutorials\.
| 

Unsupported functions
^^^^^^^^^^^^^^^^^^^^^
| Aside from the unstable extensions\,
| PyGLM doesn\'t support the following extensions and methods\, due to compatibility issues\:
| The :code:`GLM_GTC_bitfield` extension\,
| :code:`glm::log2` from GLM\_GTC\_integer\.
| :code:`glm::packUnorm` and :code:`glm::packSnorm` from GLM\_GTC\_packing\.
| 

Example
-------


::

    
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

 