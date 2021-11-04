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
&emsp;&emsp;Returns the ``` q ``` conjugate\.  
  
### lerp\(\) function  
#### <code>glm.<code>**lerp**(**x**: *float*, **y**: *float*, **a**: *float*) -\> *float*</code></code>  
&emsp;&emsp;Returns ``` x * (1.0 - a) + y * a ```, i\.e\., the linear blend of ``` x ``` and ``` y ``` using the  
&emsp;&emsp;floating\-point value ``` a ```\. The value for ``` a ``` is not restricted to the range ``` [0, 1] ```\.  
  
#### <code>glm.<code>**lerp**(**x**: *vecN*, **y**: *vecN*, **a**: *float*) -\> *vecN*</code></code>  
&emsp;&emsp;Returns ``` x * (1.0 - a) + y * a ```, i\.e\., the linear blend of ``` x ``` and ``` y ``` using the  
&emsp;&emsp;floating\-point value ``` a ```\. The value for ``` a ``` is not restricted to the range ``` [0, 1] ```\.  
  
#### <code>glm.<code>**lerp**(**x**: *vecN*, **y**: *vecN*, **a**: *vecN*) -\> *vecN*</code></code>  
&emsp;&emsp;Returns ``` x * (1.0 - a) + y * a ```, i\.e\., the linear blend of ``` x ``` and ``` y ``` using the  
&emsp;&emsp;vector ``` a ```\. The value for ``` a ``` is not restricted to the range ``` [0, 1] ```\.  
  
#### <code>glm.<code>**lerp**(**x**: *quat*, **y**: *quat*, **a**: *float*) -\> *quat*</code></code>  
&emsp;&emsp;Linear interpolation of two quaternions\. The interpolation is oriented\.  
  
### slerp\(\) function  
#### <code>glm.<code>**slerp**(**x**: *quat*, **y**: *quat*, **a**: *float*) -\> *quat*</code></code>  
&emsp;&emsp;Spherical linear interpolation of two quaternions\. The interpolation always take the short  
&emsp;&emsp;path and the rotation is performed at constant speed\.  
  
#### <code>glm.<code>**slerp**(**x**: *vec3*, **y**: *vec3*, **a**: *float*) -\> *vec3*</code></code>  
&emsp;&emsp;Returns Spherical interpolation between two vectors\.  
  
