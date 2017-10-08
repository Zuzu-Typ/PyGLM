# PyGLM ( WIP )
A semi-complete implementation of OpenGL Mathematics (GLM).

Why "semi-complete"? - PyGLM is missing some features because I wasn't able to 
implement them properly or ignored them, because I thought they weren't going
to be used by anyone anyway (like glm::tvec1).
If you want to request features, please create an issue on the issue tracker.

If you think you've found an issue, please follow these steps:
1. blame you. Maybe you were the one who caused the error.
If it wasn't you, please..
2. check for updates. Maybe I've already fixed the issue.
If that doesn't help, go ahead and..
3. blame me. Report it on the issue tracker.
If we can't find out what's causing the error, we'll have to..
4. blame GLM. Even though it's very unlikely that's what's causing the error.

PyGLM is still in active development (hence the WIP).

You can get PyGLM using the PyPI:
```pip install pyglm```

To import PyGLM's functions, simply use ```import glm```.

Example:

	import glm
	
	v = glm.vec3()
	
	v.x = 7
	
	z = v.xxx
	
	print(z)
	
You can define macros in prep.py (in the glm folder), please note though, 
that only a few are even supported.
For example:
	
	GLM_FORCE_MESSAGES = True