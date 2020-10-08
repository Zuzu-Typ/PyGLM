[//]: # (generated using SlashBack 0.2.0)

  
# type\_ptr methods  
The following methods are all part of the **type\_ptr methods**\.  
Handles the interaction between pointers and vector, matrix types\. This extension defines an overloaded function, glm\.value\_ptr\. It returns a pointer to the memory layout of the object\. Matrix types store their values in column\-major order\. This is useful for uploading data to matrices or copying data to buffer objects\.  
## Table of contents  
  
* [**make\_mat2** function](#make_mat2-function)  
* [**make\_mat2x2** function](#make_mat2x2-function)  
* [**make\_mat2x3** function](#make_mat2x3-function)  
* [**make\_mat2x4** function](#make_mat2x4-function)  
* [**make\_mat3** function](#make_mat3-function)  
* [**make\_mat3x2** function](#make_mat3x2-function)  
* [**make\_mat3x3** function](#make_mat3x3-function)  
* [**make\_mat3x4** function](#make_mat3x4-function)  
* [**make\_mat4** function](#make_mat4-function)  
* [**make\_mat4x2** function](#make_mat4x2-function)  
* [**make\_mat4x3** function](#make_mat4x3-function)  
* [**make\_mat4x4** function](#make_mat4x4-function)  
* [**make\_quat** function](#make_quat-function)  
* [**make\_vec2** function](#make_vec2-function)  
* [**make\_vec3** function](#make_vec3-function)  
* [**make\_vec4** function](#make_vec4-function)  
* [**sizeof** function](#sizeof-function)  
* [**value\_ptr** function](#value_ptr-function)  
  
### make\_mat2\(\) function  
#### <code>glm.<code>**make_mat2**(**x**: *ctypes pointer*) -\> *mat2*</code></code>  
&emsp;&emsp;See make\_mat2x2\(\)\.  
  
### make\_mat2x2\(\) function  
#### <code>glm.<code>**make_mat2x2**(**x**: *ctypes pointer*) -\> *mat2*</code></code>  
&emsp;&emsp;Build a matrix from a pointer\.  
  
### make\_mat2x3\(\) function  
#### <code>glm.<code>**make_mat2x3**(**x**: *ctypes pointer*) -\> *mat2x3*</code></code>  
&emsp;&emsp;Build a matrix from a pointer\.  
  
### make\_mat2x4\(\) function  
#### <code>glm.<code>**make_mat2x4**(**x**: *ctypes pointer*) -\> *mat2x4*</code></code>  
&emsp;&emsp;Build a matrix from a pointer\.  
  
### make\_mat3\(\) function  
#### <code>glm.<code>**make_mat3**(**x**: *ctypes pointer*) -\> *mat3*</code></code>  
&emsp;&emsp;See make\_mat3x3\(\)\.  
  
### make\_mat3x2\(\) function  
#### <code>glm.<code>**make_mat3x2**(**x**: *ctypes pointer*) -\> *mat3x2*</code></code>  
&emsp;&emsp;Build a matrix from a pointer\.  
  
### make\_mat3x3\(\) function  
#### <code>glm.<code>**make_mat3x3**(**x**: *ctypes pointer*) -\> *mat3*</code></code>  
&emsp;&emsp;Build a matrix from a pointer\.  
  
### make\_mat3x4\(\) function  
#### <code>glm.<code>**make_mat3x4**(**x**: *ctypes pointer*) -\> *mat3x4*</code></code>  
&emsp;&emsp;Build a matrix from a pointer\.  
  
### make\_mat4\(\) function  
#### <code>glm.<code>**make_mat4**(**x**: *ctypes pointer*) -\> *mat4*</code></code>  
&emsp;&emsp;See make\_mat4x4\(\)\.  
  
### make\_mat4x2\(\) function  
#### <code>glm.<code>**make_mat4x2**(**x**: *ctypes pointer*) -\> *mat4x2*</code></code>  
&emsp;&emsp;Build a matrix from a pointer\.  
  
### make\_mat4x3\(\) function  
#### <code>glm.<code>**make_mat4x3**(**x**: *ctypes pointer*) -\> *mat4*</code></code>  
&emsp;&emsp;Build a matrix from a pointer\.  
  
### make\_mat4x4\(\) function  
#### <code>glm.<code>**make_mat4x4**(**x**: *ctypes pointer*) -\> *mat4x4*</code></code>  
&emsp;&emsp;Build a matrix from a pointer\.  
  
### make\_quat\(\) function  
#### <code>glm.<code>**make_quat**(**x**: *ctypes pointer*) -\> *quat*</code></code>  
&emsp;&emsp;Build a quaternion from a pointer\.  
  
### make\_vec2\(\) function  
#### <code>glm.<code>**make_vec2**(**x**: *ctypes pointer*) -\> *vec2*</code></code>  
&emsp;&emsp;Build a vector from a pointer\.  
  
### make\_vec3\(\) function  
#### <code>glm.<code>**make_vec3**(**x**: *ctypes pointer*) -\> *vec3*</code></code>  
&emsp;&emsp;Build a vector from a pointer\.  
  
### make\_vec4\(\) function  
#### <code>glm.<code>**make_vec4**(**x**: *ctypes pointer*) -\> *vec4*</code></code>  
&emsp;&emsp;Build a vector from a pointer\.  
  
### sizeof\(\) function  
#### <code>glm.<code>**sizeof**(**x**: *type*) -\> *int*</code></code>  
&emsp;&emsp;Return the data size of x in bytes\.  
&emsp;&emsp;E\.g\. sizeof\(vec4\) == sizeof\(float32\) \* 4 = 4 \* 4 = 16\.  
  
### value\_ptr\(\) function  
#### <code>glm.<code>**value_ptr**(**x**) -\> *ctypes pointer*</code></code>  
&emsp;&emsp;Return the constant address to the data of the input parameter\.  
  
