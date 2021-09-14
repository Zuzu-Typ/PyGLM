[//]: # (generated using SlashBack 0.2.0)

  
# rotate\_vector methods  
The following methods are all part of the **rotate\_vector methods**\.  
Function to directly rotate a vector\.  
## Table of contents  
  
* [**orientation** function](#orientation-function)  
* [**rotate** function](#rotate-function)  
* [**rotateX** function](#rotatex-function)  
* [**rotateY** function](#rotatey-function)  
* [**rotateZ** function](#rotatez-function)  
* [**slerp** function](#slerp-function)  
  
### orientation\(\) function  
#### <code>glm.<code>**orientation**(**Normal**: *vec3*, **Up**: *vec3*) -\> *mat4*</code></code>  
&emsp;&emsp;Build a rotation matrix from a normal and a up vector\.  
  
### rotate\(\) function  
#### <code>glm.<code>**rotate**(**angle**: *number*, **axis**: *vec3*) -\> *mat4x4*</code></code>  
&emsp;&emsp;Builds a rotation 4 x 4 matrix created from an axis vector and an angle\.  
  
#### <code>glm.<code>**rotate**(**angle**: *number*) -\> *mat3x3*</code></code>  
&emsp;&emsp;Builds a rotation 3 x 3 matrix created from an angle\.  
  
#### <code>glm.<code>**rotate**(**m**: *mat4x4*, **angle**: *number*, **axis**: *vec3*) -\> *mat4x4*</code></code>  
&emsp;&emsp;Builds a rotation 4 x 4 matrix created from an axis vector and an angle\.  
&emsp;&emsp;``` m ``` is the input matrix multiplied by this translation matrix  
  
#### <code>glm.<code>**rotate**(**m**: *mat3x3*, **angle**: *number*) -\> *mat3x3*</code></code>  
&emsp;&emsp;Builds a rotation 3 x 3 matrix created from an angle\.  
&emsp;&emsp;``` m ``` is the input matrix multiplied by this translation matrix  
  
#### <code>glm.<code>**rotate**(**v**: *vec2*, **angle**: *float*) -\> *vec2*</code></code>  
&emsp;&emsp;Rotate a two dimensional vector\.  
  
#### <code>glm.<code>**rotate**(**v**: *vec3*, **angle**: *float*, **normal**: *vec3*) -\> *vec3*</code></code>  
&emsp;&emsp;Rotate a three dimensional vector around an axis\.  
  
#### <code>glm.<code>**rotate**(**v**: *vec4*, **angle**: *float*, **normal**: *vec3*) -\> *vec4*</code></code>  
&emsp;&emsp;Rotate a four dimensional vector around an axis\.  
  
#### <code>glm.<code>**rotate**(**q**: *quat*, **angle**: *float*, **axis**: *vec3*) -\> *quat*</code></code>  
&emsp;&emsp;Rotates a quaternion from a vector of 3 components axis and an angle\.  
  
### rotateX\(\) function  
#### <code>glm.<code>**rotateX**(**v**: *vec3*, **angle**: *float*) -\> *vec3*</code></code>  
&emsp;&emsp;Rotate a three dimensional vector around the X axis\.  
  
#### <code>glm.<code>**rotateX**(**v**: *vec4*, **angle**: *float*) -\> *vec3*</code></code>  
&emsp;&emsp;Rotate a four dimensional vector around the X axis\.  
  
### rotateY\(\) function  
#### <code>glm.<code>**rotateY**(**v**: *vec3*, **angle**: *float*) -\> *vec3*</code></code>  
&emsp;&emsp;Rotate a three dimensional vector around the Y axis\.  
  
#### <code>glm.<code>**rotateY**(**v**: *vec4*, **angle**: *float*) -\> *vec3*</code></code>  
&emsp;&emsp;Rotate a four dimensional vector around the Y axis\.  
  
### rotateZ\(\) function  
#### <code>glm.<code>**rotateZ**(**v**: *vec3*, **angle**: *float*) -\> *vec3*</code></code>  
&emsp;&emsp;Rotate a three dimensional vector around the Z axis\.  
  
#### <code>glm.<code>**rotateZ**(**v**: *vec4*, **angle**: *float*) -\> *vec3*</code></code>  
&emsp;&emsp;Rotate a four dimensional vector around the Z axis\.  
  
### slerp\(\) function  
#### <code>glm.<code>**slerp**(**x**: *quat*, **y**: *quat*, **a**: *float*) -\> *quat*</code></code>  
&emsp;&emsp;Spherical linear interpolation of two quaternions\. The interpolation always take the short  
&emsp;&emsp;path and the rotation is performed at constant speed\.  
  
#### <code>glm.<code>**slerp**(**x**: *vec3*, **y**: *vec3*, **a**: *float*) -\> *vec3*</code></code>  
&emsp;&emsp;Returns Spherical interpolation between two vectors\.  
  
