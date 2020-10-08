[//]: # (generated using SlashBack 0.2.0)

If you ever come across a situation where you need to **pass data from PyGLM**'s data types **to another library** that uses **external C code**, you should be able to accomplish your goal doing the following:  
  
It doesn't matter which kind of PyGLM type you have, but let's pretend you have a **4x4 matrix** that you need to **pass to PyOpenGL**\.  
``` Python
# a very important identity matrix
m      = glm.mat4()

# a ctypes pointer to m's data
ptr    = glm.value_ptr(m) 

# size of m's data in bytes (here 4 * 4 * 4 = 64 bytes)
nbytes = glm.sizeof(m)

glBufferData(GL_UNIFORM_BUFFER, nbytes, ptr, GL_STATIC_DRAW)
 ```  
  
This also works for any **vector, quaternion or array** type\.  
  
You can take a **shortcut for arrays** though:  
``` Python
arr = glm.array(glm.mat4(1), glm.mat4(2), glm.mat4(3))

glBufferData(GL_UNIFORM_BUFFER, arr.nbytes, arr.ptr, GL_STATIC_DRAW)
 ```