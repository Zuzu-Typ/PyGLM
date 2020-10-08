[//]: # (generated using SlashBack 0.2.0)

  
# quaternion\_common methods  
The following methods are all part of the **quaternion\_common methods**\.  
Provides common functions for quaternion types\.  
## Table of contents  
  
* [**conjugate** function](#conjugate-function)  
* [**lerp** function](#lerp-function)  
* [**slerp** function](#slerp-function)  
  
### conjugate\(\) function  
#### <code>glm.<code>**conjugate**(**q**: *quat*) -\> *quat*</code></code>  
&emsp;&emsp;Returns the q conjugate\.  
  
### lerp\(\) function  
#### <code>glm.<code>**lerp**(**x**: *quat*, **y**: *quat*, **a**: *float*) -\> *quat*</code></code>  
&emsp;&emsp;Linear interpolation of two quaternions\. The interpolation is oriented\.  
  
### slerp\(\) function  
#### <code>glm.<code>**slerp**(**x**: *quat*, **y**: *quat*, **a**: *float*) -\> *quat*</code></code>  
&emsp;&emsp;Spherical linear interpolation of two quaternions\. The interpolation always take the short  
&emsp;&emsp;path and the rotation is performed at constant speed\.  
  
