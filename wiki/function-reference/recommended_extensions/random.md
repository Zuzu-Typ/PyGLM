[//]: # (generated using SlashBack 0.2.0)

  
# random methods  
The following methods are all part of the **random methods**\.  
Generate random number from various distribution methods\.  
## Table of contents  
  
* [**ballRand** function](#ballrand-function)  
* [**circularRand** function](#circularrand-function)  
* [**diskRand** function](#diskrand-function)  
* [**gaussRand** function](#gaussrand-function)  
* [**linearRand** function](#linearrand-function)  
* [**setSeed** function](#setseed-function)  
* [**sphericalRand** function](#sphericalrand-function)  
  
### ballRand\(\) function  
#### <code>glm.<code>**ballRand**(**Radius**: *float*) -\> *vec3*</code></code>  
&emsp;&emsp;Generate a random 3D vector which coordinates are regulary distributed within the volume of  
&emsp;&emsp;a ball of a given radius\.  
  
### circularRand\(\) function  
#### <code>glm.<code>**circularRand**(**Radius**: *float*) -\> *vec2*</code></code>  
&emsp;&emsp;Generate a random 2D vector which coordinates are regulary distributed on a circle of a  
&emsp;&emsp;given radius\.  
  
### diskRand\(\) function  
#### <code>glm.<code>**diskRand**(**Radius**: *float*) -\> *vec2*</code></code>  
&emsp;&emsp;Generate a random 2D vector which coordinates are regulary distributed within the area of  
&emsp;&emsp;a disk of a given radius\.  
  
### gaussRand\(\) function  
#### <code>glm.<code>**gaussRand**(**Mean**: *float*, **Deviation**: *float*) -\> *float*</code></code>  
&emsp;&emsp;Generate random numbers in the interval \[Min, Max\], according a gaussian distribution\.  
  
#### <code>glm.<code>**gaussRand**(**Mean**: *vecN*, **Deviation**: *vecN*) -\> *vecN*</code></code>  
&emsp;&emsp;Generate random numbers in the interval \[Min, Max\], according a gaussian distribution\.  
  
### linearRand\(\) function  
#### <code>glm.<code>**linearRand**(**Min**: *float*, **Max**: *float*) -\> *float*</code></code>  
&emsp;&emsp;Generate random numbers in the interval \[Min, Max\], according a linear distribution\.  
  
#### <code>glm.<code>**linearRand**(**Min**: *vecN*, **Max**: *vecN*) -\> *vecN*</code></code>  
&emsp;&emsp;Generate random numbers in the interval \[Min, Max\], according a linear distribution\.  
  
### setSeed\(\) function  
#### <code>glm.<code>**setSeed**(**seed**: *int*) -\> *None*</code></code>  
&emsp;&emsp;Sets the seed fot the pseudo\-random number generator used by the \-Rand functions\.  
&emsp;&emsp;The seed needs to be greater or equal to zero\.  
&emsp;&emsp;Default seed is 1\.  
  
### sphericalRand\(\) function  
#### <code>glm.<code>**sphericalRand**(**Radius**: *float*) -\> *vec3*</code></code>  
&emsp;&emsp;Generate a random 3D vector which coordinates are regulary distributed on a sphere of a  
&emsp;&emsp;given radius\.  
  
