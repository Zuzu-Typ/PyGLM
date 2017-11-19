# PyGLM ( WIP )
A semi-complete implementation of OpenGL Mathematics (GLM).

Why "semi-complete"? - PyGLM is missing some features because I wasn't able to 
implement them properly or ignored them, because I thought they weren't going
to be used by anyone anyway (like glm::tvec1).
If you want to request features, please create an issue on the issue tracker.

PyGLM currently uses numpy under the hood, to improve performance. I'm currently
looking for some way to improve performance.
If you have any ideas, please leave a message on the issue tracker.

PyGLM is still in development (hence the WIP).

To install PyGLM, just use the default PyPI procedure.
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