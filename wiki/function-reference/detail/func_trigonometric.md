[//]: # (generated using SlashBack 0.2.0)

  
# func\_trigonometric methods  
The following methods are all part of the **func\_trigonometric methods**\.  
Function parameters specified as angle are assumed to be in units of radians\.  
## Table of contents  
  
* [**acos** function](#acos-function)  
* [**acosh** function](#acosh-function)  
* [**asin** function](#asin-function)  
* [**asinh** function](#asinh-function)  
* [**atan** function](#atan-function)  
* [**atanh** function](#atanh-function)  
* [**cos** function](#cos-function)  
* [**cosh** function](#cosh-function)  
* [**degrees** function](#degrees-function)  
* [**radians** function](#radians-function)  
* [**sin** function](#sin-function)  
* [**sinh** function](#sinh-function)  
* [**tan** function](#tan-function)  
* [**tanh** function](#tanh-function)  
  
### acos\(\) function  
#### <code>glm.<code>**acos**(**x**: *float*) -\> *float*</code></code>  
&emsp;&emsp;Arc cosine\. Returns an angle whose cosine is ``` x ```\. The range of values returned by this function  
&emsp;&emsp;is ``` [0, PI] ```\. Results are undefined if ``` |x| > 1 ```\.  
  
#### <code>glm.<code>**acos**(**x**: *vecN*) -\> *vecN*</code></code>  
&emsp;&emsp;Returns ``` acos(c) ``` for every component ``` c ``` of ``` x ```\.  
  
### acosh\(\) function  
#### <code>glm.<code>**acosh**(**x**: *float*) -\> *float*</code></code>  
&emsp;&emsp;Arc hyperbolic cosine; returns the non\-negative inverse of ``` cosh ```\. Results are undefined  
&emsp;&emsp;if ``` x < 1 ```\.  
  
#### <code>glm.<code>**acosh**(**x**: *vecN*) -\> *vecN*</code></code>  
&emsp;&emsp;Returns ``` acosh(c) ``` for every component ``` c ``` of ``` x ```\.  
  
### asin\(\) function  
#### <code>glm.<code>**asin**(**x**: *float*) -\> *float*</code></code>  
&emsp;&emsp;Arc sine\. Returns an angle whose sine is ``` x ```\. The range of values returned by this function  
&emsp;&emsp;is ``` [0, PI] ```\. Results are undefined if ``` |x| > 1 ```\.  
  
#### <code>glm.<code>**asin**(**x**: *vecN*) -\> *vecN*</code></code>  
&emsp;&emsp;Returns ``` asin(c) ``` for every component ``` c ``` of ``` x ```\.  
  
### asinh\(\) function  
#### <code>glm.<code>**asinh**(**x**: *float*) -\> *float*</code></code>  
&emsp;&emsp;Arc hyperbolic sine; returns the inverse of ``` sinh ```\.  
  
#### <code>glm.<code>**asinh**(**x**: *vecN*) -\> *vecN*</code></code>  
&emsp;&emsp;Returns ``` asinh(c) ``` for every component ``` c ``` of ``` x ```\.  
  
### atan\(\) function  
#### <code>glm.<code>**atan**(**y_over_x**: *float*) -\> *float*</code></code>  
&emsp;&emsp;Arc tangent\. Returns an angle whose tangent is ``` y_over_x ```\. The range of values returned by  
&emsp;&emsp;this function is ``` [-PI / 2, PI / 2] ```\.  
  
#### <code>glm.<code>**atan**(**y_over_x**: *vecN*) -\> *vecN*</code></code>  
&emsp;&emsp;Returns ``` atan(c) ``` for every component ``` c ``` of ``` x ```\.  
  
#### <code>glm.<code>**atan**(**y**: *float*, **x**: *float*) -\> *float*</code></code>  
&emsp;&emsp;Arc tangent\. Returns an angle whose tangent is ``` y / x ```\. The signs of ``` x ``` and ``` y ``` are used to  
&emsp;&emsp;determine what quadrant the angle is in\. The range of values returned by this function  
&emsp;&emsp;is ``` [-PI, PI] ```\. Results are undefined if ``` x ``` and ``` y ``` are both ``` 0 ```\.  
  
#### <code>glm.<code>**atan**(**y**: *vecN*, **x**: *vecN*) -\> *vecN*</code></code>  
&emsp;&emsp;Returns ``` atan(y[i], x[i]) ``` for every index ``` i ```\.  
  
### atanh\(\) function  
#### <code>glm.<code>**atanh**(**x**: *float*) -\> *float*</code></code>  
&emsp;&emsp;Arc hyperbolic tangent; returns the inverse of ``` tanh ```\. Results are undefined if ``` abs(x) >= 1 ```\.  
  
#### <code>glm.<code>**atanh**(**x**: *vecN*) -\> *vecN*</code></code>  
&emsp;&emsp;Returns ``` atanh(c) ``` for every component ``` c ``` of ``` x ```\.  
  
### cos\(\) function  
#### <code>glm.<code>**cos**(**angle**: *float*) -\> *float*</code></code>  
&emsp;&emsp;The standard trigonometric cosine function\. The values returned by this function will range  
&emsp;&emsp;from ``` [-1, 1] ```\.  
  
#### <code>glm.<code>**cos**(**angle**: *vecN*) -\> *vecN*</code></code>  
&emsp;&emsp;Returns ``` cos(c) ``` for every component ``` c ``` of ``` x ```\.  
  
### cosh\(\) function  
#### <code>glm.<code>**cosh**(**angle**: *float*) -\> *float*</code></code>  
&emsp;&emsp;Returns the hyperbolic cosine function, ``` (exp(angle) + exp(-angle)) / 2 ```\.  
  
#### <code>glm.<code>**cosh**(**angle**: *vecN*) -\> *vecN*</code></code>  
&emsp;&emsp;Returns ``` cosh(c) ``` for every component ``` c ``` of ``` x ```\.  
  
### degrees\(\) function  
#### <code>glm.<code>**degrees**(**angle**: *float*) -\> *float*</code></code>  
&emsp;&emsp;Converts radians to degrees and returns the result\.  
  
#### <code>glm.<code>**degrees**(**angle**: *vecN*) -\> *vecN*</code></code>  
&emsp;&emsp;Returns ``` degrees(c) ``` for every component ``` c ``` of ``` x ```\.  
  
### radians\(\) function  
#### <code>glm.<code>**radians**(**angle**: *float*) -\> *float*</code></code>  
&emsp;&emsp;Converts degrees to radians and returns the result\.  
  
#### <code>glm.<code>**radians**(**angle**: *vecN*) -\> *vecN*</code></code>  
&emsp;&emsp;Returns ``` radians(c) ``` for every component ``` c ``` of ``` x ```\.  
  
### sin\(\) function  
#### <code>glm.<code>**sin**(**angle**: *float*) -\> *float*</code></code>  
&emsp;&emsp;The standard trigonometric sine function\. The values returned by this function will range  
&emsp;&emsp;from ``` [-1, 1] ```\.  
  
#### <code>glm.<code>**sin**(**angle**: *vecN*) -\> *vecN*</code></code>  
&emsp;&emsp;Returns ``` sin(c) ``` for every component ``` c ``` of ``` x ```\.  
  
### sinh\(\) function  
#### <code>glm.<code>**sinh**(**angle**: *float*) -\> *float*</code></code>  
&emsp;&emsp;Returns the hyperbolic sine function, ``` (exp(angle) - exp(-angle)) / 2 ```\.  
  
#### <code>glm.<code>**sinh**(**angle**: *vecN*) -\> *vecN*</code></code>  
&emsp;&emsp;Returns ``` sinh(c) ``` for every component ``` c ``` of ``` x ```\.  
  
### tan\(\) function  
#### <code>glm.<code>**tan**(**angle**: *float*) -\> *float*</code></code>  
&emsp;&emsp;The standard trigonometric tangent function\.  
  
#### <code>glm.<code>**tan**(**angle**: *vecN*) -\> *vecN*</code></code>  
&emsp;&emsp;Returns ``` tan(c) ``` for every component ``` c ``` of ``` x ```\.  
  
### tanh\(\) function  
#### <code>glm.<code>**tanh**(**angle**: *float*) -\> *float*</code></code>  
&emsp;&emsp;Returns the hyperbolic tangent function, ``` sinh(angle) / cosh(angle) ```  
  
#### <code>glm.<code>**tanh**(**angle**: *vecN*) -\> *vecN*</code></code>  
&emsp;&emsp;Returns ``` tanh(c) ``` for every component ``` c ``` of ``` x ```\.  
  
