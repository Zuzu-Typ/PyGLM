[//]: # (generated using SlashBack 0.2.0)

  
# ulp methods  
The following methods are all part of the **ulp methods**\.  
Allow the measurement of the accuracy of a function against a reference implementation\. This extension works on floating\-point data and provide results in ULP\.  
## Table of contents  
  
* [**float\_distance** function](#float_distance-function)  
* [**next\_float** function](#next_float-function)  
* [**prev\_float** function](#prev_float-function)  
  
### float\_distance\(\) function  
#### <code>glm.<code>**float_distance**(**x**: *float*, **y**: *float*) -\> *float*</code></code>  
&emsp;&emsp;Return the distance in the number of ULP between 2 double\-precision floating\-point scalars\.  
  
#### <code>glm.<code>**float_distance**(**x**: *fvecN*, **y**: *fvecN*) -\> *ivecN*</code></code>  
&emsp;&emsp;Return the distance in the number of ULP between 2 single\-precision floating\-point scalars\.  
  
#### <code>glm.<code>**float_distance**(**x**: *dvecN*, **y**: *dvecN*) -\> *i64vecN*</code></code>  
&emsp;&emsp;Return the distance in the number of ULP between 2 double\-precision floating\-point scalars\.  
  
### next\_float\(\) function  
#### <code>glm.<code>**next_float**(**x**: *float*) -\> *float*</code></code>  
&emsp;&emsp;Return the next ULP value\(s\) after the input value\(s\)\.  
  
#### <code>glm.<code>**next_float**(**x**: *vecN*) -\> *vecN*</code></code>  
&emsp;&emsp;Return the next ULP value\(s\) after the input value\(s\)\.  
  
#### <code>glm.<code>**next_float**(**x**: *float*, **ULPs**: *float*) -\> *float*</code></code>  
&emsp;&emsp;Return the next ULP value\(s\) after the input value\(s\)\.  
  
#### <code>glm.<code>**next_float**(**x**: *vecN*, **ULPs**: *float*) -\> *vecN*</code></code>  
&emsp;&emsp;Return the next ULP value\(s\) after the input value\(s\)\.  
  
#### <code>glm.<code>**next_float**(**x**: *vecN*, **ULPs**: *ivecN*) -\> *float*</code></code>  
&emsp;&emsp;Return the next ULP value\(s\) after the input value\(s\)\.  
  
### prev\_float\(\) function  
#### <code>glm.<code>**prev_float**(**x**: *float*) -\> *float*</code></code>  
&emsp;&emsp;Return the previous ULP value\(s\) before the input value\(s\)\.  
  
#### <code>glm.<code>**prev_float**(**x**: *vecN*) -\> *vecN*</code></code>  
&emsp;&emsp;Return the previous ULP value\(s\) before the input value\(s\)\.  
  
#### <code>glm.<code>**prev_float**(**x**: *float*, **ULPs**: *float*) -\> *float*</code></code>  
&emsp;&emsp;Return the previous ULP value\(s\) before the input value\(s\)\.  
  
#### <code>glm.<code>**prev_float**(**x**: *vecN*, **ULPs**: *float*) -\> *vecN*</code></code>  
&emsp;&emsp;Return the previous ULP value\(s\) before the input value\(s\)\.  
  
#### <code>glm.<code>**prev_float**(**x**: *vecN*, **ULPs**: *ivecN*) -\> *float*</code></code>  
&emsp;&emsp;Return the previous ULP value\(s\) before the input value\(s\)\.  
  
