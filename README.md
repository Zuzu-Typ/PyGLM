# PyGLM ( WIP )
A only-the-necessary implementation of OpenGL Mathematics (GLM).

What I mean by "only-the-necessary"? - Some features the original GLM has, PyGLM
doesn't. For example, there is no "tvec1". (The reason for this being that it
didn't seem worth the effort it would take to implement it).
If you find yourself missing a feature, please create an issue on the issue tracker.

PyGLM currently uses numpy under the hood, to improve performance,
though I am working on a GLM Python C-API extension, which will be more
than 10 times as fast.
The basic types are already finished, you can find them (and already built glm packages)
under the "src/" directory.

PyGLM is still in development (hence the WIP).

To install PyGLM the usual way, just use the default PyPI procedure.
```pip install pyglm```

To import PyGLM's functions, simply use ```import glm```.

I might put up a doc if I find the time.
For now, please refer to GLM docs.

Example:

	import glm
	
	v = glm.vec3()
	
	v.x = 7
	
	z = v.xxx
	
	print(z) # prints "tvec3( 7, 7, 7 )"