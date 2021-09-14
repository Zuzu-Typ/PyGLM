[//]: # (generated using SlashBack 0.2.0)

  
# matrix\_transform\_2d methods  
The following methods are all part of the **matrix\_transform\_2d methods**\.  
Defines functions that generate common 2d transformation matrices\.  
## Table of contents  
  
* [**rotate** function](#rotate-function)  
* [**scale** function](#scale-function)  
* [**shearX** function](#shearx-function)  
* [**shearY** function](#sheary-function)  
* [**translate** function](#translate-function)  
  
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
  
### scale\(\) function  
#### <code>glm.<code>**scale**(**v**: *vec3*) -\> *mat4x4*</code></code>  
&emsp;&emsp;Builds a scale 4 x 4 matrix created from 3 scalars\.  
  
#### <code>glm.<code>**scale**(**v**: *vec2*) -\> *mat3x3*</code></code>  
&emsp;&emsp;Builds a scale 3 x 3 matrix created from a vector of 2 components\.  
  
#### <code>glm.<code>**scale**(**m**: *mat4x4*, **v**: *vec3*) -\> *mat4x4*</code></code>  
&emsp;&emsp;Builds a scale 4 x 4 matrix created from 3 scalars\.  
&emsp;&emsp;``` m ``` is the input matrix multiplied by this translation matrix  
  
#### <code>glm.<code>**scale**(**m**: *mat3x3*, **v**: *vec2*) -\> *mat3x3*</code></code>  
&emsp;&emsp;Builds a scale 3 x 3 matrix created from a vector of 2 components\.  
&emsp;&emsp;``` m ``` is the input matrix multiplied by this translation matrix  
  
### shearX\(\) function  
#### <code>glm.<code>**shearX**(**m**: *mat3x3*, **y**: *number*) -\> *mat3x3*</code></code>  
&emsp;&emsp;Builds an horizontal \(parallel to the x axis\) shear 3 x 3 matrix\.  
&emsp;&emsp;``` m ``` is the input matrix multiplied by this translation matrix  
  
### shearY\(\) function  
#### <code>glm.<code>**shearY**(**m**: *mat3x3*, **x**: *number*) -\> *mat3x3*</code></code>  
&emsp;&emsp;Builds a vertical \(parallel to the y axis\) shear 3 x 3 matrix\.  
&emsp;&emsp;``` m ``` is the input matrix multiplied by this translation matrix  
  
### translate\(\) function  
#### <code>glm.<code>**translate**(**v**: *vec3*) -\> *mat4x4*</code></code>  
&emsp;&emsp;Builds a translation 4 x 4 matrix created from a vector of 3 components\.  
  
#### <code>glm.<code>**translate**(**v**: *vec2*) -\> *mat3x3*</code></code>  
&emsp;&emsp;Builds a translation 3 x 3 matrix created from a vector of 2 components\.  
  
#### <code>glm.<code>**translate**(**m**: *mat4x4*, **v**: *vec3*) -\> *mat4x4*</code></code>  
&emsp;&emsp;Builds a translation 4 x 4 matrix created from a vector of 3 components\.  
&emsp;&emsp;``` m ``` is the input matrix multiplied by this translation matrix  
  
#### <code>glm.<code>**translate**(**m**: *mat3x3*, **v**: *vec2*) -\> *mat3x3*</code></code>  
&emsp;&emsp;Builds a translation 3 x 3 matrix created from a vector of 2 components\.  
&emsp;&emsp;``` m ``` is the input matrix multiplied by this translation matrix  
  
