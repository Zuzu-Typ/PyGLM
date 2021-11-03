[//]: # (generated using SlashBack 0.2.0)

  
# compatibility methods  
The following methods are all part of the **compatibility methods**\.  
Provide functions to increase the compatibility with Cg and HLSL languages\.  
## Table of contents  
  
* [**atan2** function](#atan2-function)  
* [**isfinite** function](#isfinite-function)  
* [**lerp** function](#lerp-function)  
* [**saturate** function](#saturate-function)  
  
### atan2\(\) function  
#### <code>glm.<code>**atan2**(**y**: *float*, **x**: *float*) -\> *float*</code></code>  
&emsp;&emsp;Arc tangent\. Returns an angle whose tangent is ``` y / x ```\. The signs of ``` x ``` and ``` y ``` are used to  
&emsp;&emsp;determine what quadrant the angle is in\. The range of values returned by this function  
&emsp;&emsp;is ``` [-PI, PI] ```\. Results are undefined if ``` x ``` and ``` y ``` are both ``` 0 ```\.  
&emsp;&emsp;Alias for ``` atan ```\.  
  
#### <code>glm.<code>**atan2**(**y**: *vecN*, **x**: *vecN*) -\> *vecN*</code></code>  
&emsp;&emsp;Returns ``` atan(y[i], x[i]) ``` for every index ``` i ```\.  
&emsp;&emsp;Alias for ``` atan ```\.  
  
### isfinite\(\) function  
#### <code>glm.<code>**isfinite**(**x**: *float*) -\> *bool*</code></code>  
&emsp;&emsp;Test whether or not a scalar is a finite value\.  
  
#### <code>glm.<code>**isfinite**(**x**: *vecN*) -\> *bvecN*</code></code>  
&emsp;&emsp;Test whether or not each vector component is a finite value\.  
  
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
  
### saturate\(\) function  
#### <code>glm.<code>**saturate**(**x**: *float*) -\> *float*</code></code>  
&emsp;&emsp;Returns ``` clamp(x, 0, 1) ```\.  
  
#### <code>glm.<code>**saturate**(**x**: *vecN*) -\> *vecN*</code></code>  
&emsp;&emsp;Returns ``` clamp(x, 0, 1) ```\.  
  
