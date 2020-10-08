[//]: # (generated using SlashBack 0.2.0)

  
# func\_exponential methods  
The following methods are all part of the **func\_exponential methods**\.  
It contains exponential GLSL functions\.  
## Table of contents  
  
* [**exp** function](#exp-function)  
* [**exp2** function](#exp2-function)  
* [**inversesqrt** function](#inversesqrt-function)  
* [**log** function](#log-function)  
* [**log2** function](#log2-function)  
* [**pow** function](#pow-function)  
* [**sqrt** function](#sqrt-function)  
  
### exp\(\) function  
#### <code>glm.<code>**exp**(**x**: *float*) -\> *float*</code></code>  
&emsp;&emsp;Returns the natural exponentiation of x, i\.e\., e^x\.  
  
#### <code>glm.<code>**exp**(**x**: *vecN*) -\> *vecN*</code></code>  
&emsp;&emsp;For every component c of x:  
&emsp;&emsp;Returns the natural exponentiation of c, i\.e\., e^c\.  
  
#### <code>glm.<code>**exp**(**x**: *quat*) -\> *quat*</code></code>  
&emsp;&emsp;Returns an exponential of a quaternion\.  
  
### exp2\(\) function  
#### <code>glm.<code>**exp2**(**x**: *float*) -\> *float*</code></code>  
&emsp;&emsp;Returns 2 raised to the x power\.  
  
#### <code>glm.<code>**exp2**(**x**: *vecN*) -\> *vecN*</code></code>  
&emsp;&emsp;For every component c of x:  
&emsp;&emsp;Returns 2 raised to the c power\.  
  
### inversesqrt\(\) function  
#### <code>glm.<code>**inversesqrt**(**x**: *float*) -\> *float*</code></code>  
&emsp;&emsp;Returns the reciprocal of the positive square root of x\.  
  
#### <code>glm.<code>**inversesqrt**(**x**: *vecN*) -\> *vecN*</code></code>  
&emsp;&emsp;For every component c of x:  
&emsp;&emsp;Returns the reciprocal of the positive square root of c\.  
  
### log\(\) function  
#### <code>glm.<code>**log**(**x**: *float*) -\> *float*</code></code>  
&emsp;&emsp;Returns the natural logarithm of x, i\.e\., returns the value y which satisfies the equation  
&emsp;&emsp;x = e^y\. Results are undefined if x &lt;= 0\.  
  
#### <code>glm.<code>**log**(**x**: *vecN*) -\> *vecN*</code></code>  
&emsp;&emsp;For every component c of x:  
&emsp;&emsp;Returns the natural logarithm of c, i\.e\., returns the value y which satisfies the equation  
&emsp;&emsp;c = e^y\. Results are undefined if c &lt;= 0\.  
  
#### <code>glm.<code>**log**(**x**: *quat*) -\> *quat*</code></code>  
&emsp;&emsp;Returns a logarithm of a quaternion\.  
  
### log2\(\) function  
#### <code>glm.<code>**log2**(**x**: *float*) -\> *float*</code></code>  
&emsp;&emsp;Returns the base 2 log of x, i\.e\., returns the value y, which satisfies the equation x = 2 ^ y\.  
  
#### <code>glm.<code>**log2**(**x**: *vecN*) -\> *vecN*</code></code>  
&emsp;&emsp;For every component c of x:  
&emsp;&emsp;Returns the base 2 log of c, i\.e\., returns the value y, which satisfies the equation c = 2 ^ y\.  
  
### pow\(\) function  
#### <code>glm.<code>**pow**(**base**: *float*, **exponent**: *float*) -\> *float*</code></code>  
&emsp;&emsp;Returns base raised to the power exponent\.  
  
#### <code>glm.<code>**pow**(**base**: *vecN*, **exponent**: *vecN*) -\> *vecN*</code></code>  
&emsp;&emsp;For every index i:  
&emsp;&emsp;Returns base\[i\] raised to the power exponent\[i\]\.  
  
#### <code>glm.<code>**pow**(**base**: *quat*, **exponent**: *quat*) -\> *quat*</code></code>  
&emsp;&emsp;Returns a quaternion raised to a power\.  
  
### sqrt\(\) function  
#### <code>glm.<code>**sqrt**(**x**: *float*) -\> *float*</code></code>  
&emsp;&emsp;Returns the positive square root of x\.  
  
#### <code>glm.<code>**sqrt**(**x**: *vecN*) -\> *vecN*</code></code>  
&emsp;&emsp;For every component c of x:  
&emsp;&emsp;Returns the positive square root of c\.  
  
#### <code>glm.<code>**sqrt**(**x**: *quat*) -\> *quat*</code></code>  
&emsp;&emsp;Returns the square root of a quaternion\.  
  
