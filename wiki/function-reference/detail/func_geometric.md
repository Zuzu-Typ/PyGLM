[//]: # (generated using SlashBack 0.2.0)

  
# func\_geometric methods  
The following methods are all part of the **func\_geometric methods**\.  
These operate on vectors as vectors, not component\-wise\.  
## Table of contents  
  
* [**cross** function](#cross-function)  
* [**distance** function](#distance-function)  
* [**dot** function](#dot-function)  
* [**faceforward** function](#faceforward-function)  
* [**length** function](#length-function)  
* [**normalize** function](#normalize-function)  
* [**reflect** function](#reflect-function)  
* [**refract** function](#refract-function)  
  
### cross\(\) function  
#### <code>glm.<code>**cross**(**x**: *vec3*, **y**: *vec3*) -\> *vec3*</code></code>  
&emsp;&emsp;Returns the cross product of ``` x ``` and ``` y ```\.  
  
#### <code>glm.<code>**cross**(**x**: *quat*, **y**: *quat*) -\> *quat*</code></code>  
&emsp;&emsp;Compute a cross product\.  
  
### distance\(\) function  
#### <code>glm.<code>**distance**(**p0**: *float*, **p1**: *float*) -\> *float*</code></code>  
&emsp;&emsp;Returns the distance between ``` p0 ``` and ``` p1 ```, i\.e\., ``` length(p0 - p1) ```\.  
  
#### <code>glm.<code>**distance**(**p0**: *vecN*, **p1**: *vecN*) -\> *float*</code></code>  
&emsp;&emsp;Returns the distance between ``` p0 ``` and ``` p1 ```, i\.e\., ``` length(p0 - p1) ```\.  
  
### dot\(\) function  
#### <code>glm.<code>**dot**(**x**: *number*, **y**: *number*) -\> *float*</code></code>  
&emsp;&emsp;Returns the dot product of ``` x ``` and ``` y ```, i\.e\., ``` result = x * y ```\.  
  
#### <code>glm.<code>**dot**(**x**: *vecN*, **y**: *vecN*) -\> *number*</code></code>  
&emsp;&emsp;Returns the dot product of ``` x ``` and ``` y ```, i\.e\., ``` result = x[0] * y[0] + x[1] * y[1] + ... ```  
  
#### <code>glm.<code>**dot**(**x**: *quat*, **y**: *quat*) -\> *float*</code></code>  
&emsp;&emsp;Returns dot product of ``` x ``` and ``` y ```, i\.e\., ``` x[0] * y[0] + x[1] * y[1] + ... ```  
  
### faceforward\(\) function  
#### <code>glm.<code>**faceforward**(**N**: *float*, **I**: *float*, **Nref**: *float*) -\> *float*</code></code>  
&emsp;&emsp;If ``` dot(Nref, I) < 0.0 ```, return ``` N ```, otherwise, return ``` -N ```\.  
  
#### <code>glm.<code>**faceforward**(**N**: *vecN*, **I**: *vecN*, **Nref**: *vecN*) -\> *vecN*</code></code>  
&emsp;&emsp;For every index ``` i ```:  
&emsp;&emsp;If ``` dot(Nref[i], I[i]) < 0.0 ```, return ``` N[i] ```, otherwise, return ``` -N[i] ```\.  
  
### length\(\) function  
#### <code>glm.<code>**length**(**x**: *float*) -\> *float*</code></code>  
&emsp;&emsp;Returns the length of ``` x ```, i\.e\., ``` abs(x) ```\.  
  
#### <code>glm.<code>**length**(**x**: *vecN*) -\> *float*</code></code>  
&emsp;&emsp;Returns the length of ``` x ```, i\.e\., ``` sqrt(x * x) ```\.  
  
#### <code>glm.<code>**length**(**x**: *quat*) -\> *float*</code></code>  
&emsp;&emsp;Returns the norm of a quaternion\.  
  
### normalize\(\) function  
#### <code>glm.<code>**normalize**(**x**: *vecN*) -\> *vecN*</code></code>  
&emsp;&emsp;Returns a vector in the same direction as ``` x ``` but with length of ``` 1 ```\.  
  
#### <code>glm.<code>**normalize**(**x**: *quat*) -\> *quat*</code></code>  
&emsp;&emsp;Returns the normalized quaternion\.  
  
### reflect\(\) function  
#### <code>glm.<code>**reflect**(**I**: *float*, **N**: *float*) -\> *float*</code></code>  
&emsp;&emsp;For the incident vector ``` I ``` and surface orientation ``` N ```, returns the reflection direction:  
&emsp;&emsp;``` result = I - 2.0 * dot(N, I) * N ```\.  
  
#### <code>glm.<code>**reflect**(**I**: *vecN*, **N**: *vecN*) -\> *vecN*</code></code>  
&emsp;&emsp;For the incident vector ``` I ``` and surface orientation ``` N ```, returns the reflection direction:  
&emsp;&emsp;``` result = I - 2.0 * dot(N, I) * N ```\.  
  
### refract\(\) function  
#### <code>glm.<code>**refract**(**I**: *float*, **N**: *float*, **eta**: *float*) -\> *float*</code></code>  
&emsp;&emsp;For the incident vector ``` I ``` and surface normal ``` N ```, and the ratio of indices of refraction ``` eta ```,  
&emsp;&emsp;return the refraction vector\.  
  
#### <code>glm.<code>**refract**(**I**: *vecN*, **N**: *vecN*, **eta**: *float*) -\> *vecN*</code></code>  
&emsp;&emsp;For the incident vector ``` I ``` and surface normal ``` N ```, and the ratio of indices of refraction ``` eta ```,  
&emsp;&emsp;return the refraction vector\.  
  
