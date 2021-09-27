[//]: # (generated using SlashBack 0.2.0)

  
# func\_common methods  
The following methods are all part of the **func\_common methods**\.  
It contains common GLSL functions\.  
## Table of contents  
  
* [**abs** function](#abs-function)  
* [**ceil** function](#ceil-function)  
* [**clamp** function](#clamp-function)  
* [**floatBitsToInt** function](#floatbitstoint-function)  
* [**floatBitsToUint** function](#floatbitstouint-function)  
* [**floor** function](#floor-function)  
* [**fma** function](#fma-function)  
* [**fmax** function](#fmax-function)  
* [**fmin** function](#fmin-function)  
* [**fract** function](#fract-function)  
* [**frexp** function](#frexp-function)  
* [**intBitsToFloat** function](#intbitstofloat-function)  
* [**isinf** function](#isinf-function)  
* [**isnan** function](#isnan-function)  
* [**ldexp** function](#ldexp-function)  
* [**max** function](#max-function)  
* [**min** function](#min-function)  
* [**mix** function](#mix-function)  
* [**mod** function](#mod-function)  
* [**modf** function](#modf-function)  
* [**round** function](#round-function)  
* [**roundEven** function](#roundeven-function)  
* [**sign** function](#sign-function)  
* [**smoothstep** function](#smoothstep-function)  
* [**step** function](#step-function)  
* [**trunc** function](#trunc-function)  
* [**uintBitsToFloat** function](#uintbitstofloat-function)  
  
### abs\(\) function  
#### <code>glm.<code>**abs**(**x**: *float*) -\> *float*</code></code>  
&emsp;&emsp;Returns ``` x ``` if ``` x >= 0 ```; otherwise it returns ``` -x ```\.  
  
#### <code>glm.<code>**abs**(**x**: *vecN*) -\> *vecN*</code></code>  
&emsp;&emsp;For each component ``` c ``` of ``` x ```,  
&emsp;&emsp;Returns ``` c ``` if ``` c >= 0 ```; otherwise it returns ``` -c ```\.  
  
### ceil\(\) function  
#### <code>glm.<code>**ceil**(**x**: *float*) -\> *float*</code></code>  
&emsp;&emsp;Returns a value equal to the nearest integer that is greater than or equal to ``` x ```\.  
  
#### <code>glm.<code>**ceil**(**x**: *vecN*) -\> *vecN*</code></code>  
&emsp;&emsp;For each component ``` c ``` of ``` x ```,  
&emsp;&emsp;Returns a value equal to the nearest integer that is greater than or equal to ``` c ```\.  
  
### clamp\(\) function  
#### <code>glm.<code>**clamp**(**x**: *number*, **minVal**: *number*, **maxVal**: *number*) -\> *number*</code></code>  
&emsp;&emsp;Returns ``` min(max(x, minVal), maxVal) ```\.  
  
#### <code>glm.<code>**clamp**(**x**: *vecN*, **minVal**: *number*, **maxVal**: *number*) -\> *vecN*</code></code>  
&emsp;&emsp;Returns ``` min(max(x, minVal), maxVal) ``` for each component in ``` x ``` using the floating\-point values  
&emsp;&emsp;``` minVal ``` and ``` maxVal ```\.  
  
#### <code>glm.<code>**clamp**(**x**: *vecN*, **minVal**: *vecN*, **maxVal**: *vecN*) -\> *vecN*</code></code>  
&emsp;&emsp;Returns ``` min(max(x, minVal), maxVal) ``` for each component in ``` x ``` using the floating\-point values  
&emsp;&emsp;``` minVal ``` and ``` maxVal ```\.  
  
### floatBitsToInt\(\) function  
#### <code>glm.<code>**floatBitsToInt**(**v**: *float*) -\> *int*</code></code>  
&emsp;&emsp;Returns a signed integer value representing the encoding of a floating\-point value\.  
&emsp;&emsp;The floating\-point value's bit\-level representation is preserved\.  
  
#### <code>glm.<code>**floatBitsToInt**(**v**: *fvecN*) -\> *ivecN*</code></code>  
&emsp;&emsp;Returns a signed integer value representing the encoding of a floating\-point value\.  
&emsp;&emsp;The floating\-point value's bit\-level representation is preserved\.  
  
### floatBitsToUint\(\) function  
#### <code>glm.<code>**floatBitsToUint**(**v**: *float*) -\> *int*</code></code>  
&emsp;&emsp;Returns an unsigned integer value representing the encoding of a floating\-point value\.  
&emsp;&emsp;The floating\-point value's bit\-level representation is preserved\.  
  
#### <code>glm.<code>**floatBitsToUint**(**v**: *fvecN*) -\> *uvecN*</code></code>  
&emsp;&emsp;Returns an unsigned integer value representing the encoding of a floating\-point value\.  
&emsp;&emsp;The floating\-point value's bit\-level representation is preserved\.  
  
### floor\(\) function  
#### <code>glm.<code>**floor**(**x**: *float*) -\> *float*</code></code>  
&emsp;&emsp;Returns a value equal to the nearest integer that is less then or equal to ``` x ```\.  
  
#### <code>glm.<code>**floor**(**v**: *vecN*) -\> *vecN*</code></code>  
&emsp;&emsp;For each component ``` c ``` of ``` v ```:  
&emsp;&emsp;Returns a value equal to the nearest integer that is less then or equal to ``` c ```\.  
  
### fma\(\) function  
#### <code>glm.<code>**fma**(**a**: *float*, **b**: *float*, **c**: *float*) -\> *float*</code></code>  
&emsp;&emsp;Computes and returns ``` a * b + c ```\.  
  
### fmax\(\) function  
#### <code>glm.<code>**fmax**(**x**: *number*, **y**: *number*) -\> *float*</code></code>  
&emsp;&emsp;Returns ``` y ``` if ``` x < y ```; otherwise, it returns ``` x ```\. If one of the two arguments is ``` NaN ```, the value  
&emsp;&emsp;of the other argument is returned\.  
  
#### <code>glm.<code>**fmax**(**x**: *vecN*, **y**: *number*) -\> *vecN*</code></code>  
&emsp;&emsp;For each component ``` c ``` of ``` x ```:  
&emsp;&emsp;Returns ``` y ``` if ``` c < y ```; otherwise, it returns ``` c ```\. If one of the two arguments is ``` NaN ```, the value  
&emsp;&emsp;of the other argument is returned\.  
  
#### <code>glm.<code>**fmax**(**x**: *vecN*, **y**: *vecN*) -\> *vecN*</code></code>  
&emsp;&emsp;For every index ``` i ```:  
&emsp;&emsp;Returns ``` y[i] ``` if ``` x[i] < y[i] ```; otherwise, it returns ``` x[i] ```\. If one of the two arguments is  
&emsp;&emsp;``` NaN ```, the value of the other argument is returned\.  
  
#### <code>glm.<code>**fmax**(**a**: *vecN*, **b**: *vecN*, **c**: *vecN*) -\> *vecN*</code></code>  
&emsp;&emsp;Returns ``` fmax(fmax(a, b), c) ```\.  
  
#### <code>glm.<code>**fmax**(**a**: *vecN*, **b**: *vecN*, **c**: *vecN*, **d**: *vecN*) -\> *vecN*</code></code>  
&emsp;&emsp;Returns ``` fmax(fmax(a, b), fmax(c, d)) ```\.  
  
### fmin\(\) function  
#### <code>glm.<code>**fmin**(**x**: *number*, **y**: *number*) -\> *float*</code></code>  
&emsp;&emsp;Returns ``` y ``` if ``` y < x ```; otherwise, it returns ``` x ```\. If one of the two arguments is ``` NaN ```, the value  
&emsp;&emsp;of the other argument is returned\.  
  
#### <code>glm.<code>**fmin**(**x**: *vecN*, **y**: *number*) -\> *vecN*</code></code>  
&emsp;&emsp;For each component ``` c ``` of ``` x ```:  
&emsp;&emsp;Returns ``` y ``` if ``` y < c ```; otherwise, it returns ``` c ```\. If one of the two arguments is ``` NaN ```, the value  
&emsp;&emsp;of the other argument is returned\.  
  
#### <code>glm.<code>**fmin**(**x**: *vecN*, **y**: *vecN*) -\> *vecN*</code></code>  
&emsp;&emsp;For every index ``` i ```:  
&emsp;&emsp;Returns ``` y[i] ``` if ``` y[i] < x[i] ```; otherwise, it returns ``` x[i] ```\. If one of the two arguments is  
&emsp;&emsp;``` NaN ```, the value of the other argument is returned\.  
  
#### <code>glm.<code>**fmin**(**a**: *vecN*, **b**: *vecN*, **c **: *vecN*) -\> *vecN*</code></code>  
&emsp;&emsp;Returns ``` fmin(fmin(a, b), c) ```\.  
  
#### <code>glm.<code>**fmin**(**a**: *vecN*, **b**: *vecN*, **c **: *vecN*, **d**: *vecN*) -\> *vecN*</code></code>  
&emsp;&emsp;Returns ``` fmin(fmin(a, b), fmin(c, d)) ```\.  
  
### fract\(\) function  
#### <code>glm.<code>**fract**(**x**: *float*) -\> *float*</code></code>  
&emsp;&emsp;Returns ``` x - floor(x) ```\.  
  
#### <code>glm.<code>**fract**(**c**: *vecN*) -\> *vecN*</code></code>  
&emsp;&emsp;Returns ``` x - floor(x) ```\.  
  
### frexp\(\) function  
#### <code>glm.<code>**frexp**(**x**: *float*) -\> *(significant: float, exponent: int)*</code></code>  
&emsp;&emsp;Splits ``` x ``` into a floating\-point significand in the range ``` [0.5, 1.0) ``` and an integral exponent  
&emsp;&emsp;of two, such that: ``` x = significand * exp(2, exponent) ```  
  
#### <code>glm.<code>**frexp**(**x**: *vecN*, **exp**: *ivecN*) -\> *vecN*</code></code>  
&emsp;&emsp;Splits ``` x ``` into a floating\-point significand in the range ``` [0.5, 1.0) ``` and an integral exponent  
&emsp;&emsp;of two, such that: ``` x = significand * exp(2, exponent) ```  
&emsp;&emsp;The significand is returned by the function and the exponent is returned in the parameter  
&emsp;&emsp;``` exp ```\. For a floating\-point value of zero, the significantand exponent are both zero\. For a  
&emsp;&emsp;floating\-point value that is an infinity or is not a number, the results are undefined\.  
  
### intBitsToFloat\(\) function  
#### <code>glm.<code>**intBitsToFloat**(**v**: *int*) -\> *float*</code></code>  
&emsp;&emsp;Returns a floating\-point value corresponding to a signed integer encoding of a floating\-point  
&emsp;&emsp;value\. If an ``` inf ``` or ``` NaN ``` is passed in, it will not signal, and the resulting floating point  
&emsp;&emsp;value is unspecified\. Otherwise, the bit\-level representation is preserved\.  
  
#### <code>glm.<code>**intBitsToFloat**(**v**: *ivecN*) -\> *fvecN*</code></code>  
&emsp;&emsp;Returns a floating\-point value corresponding to a signed integer encoding of a floating\-point  
&emsp;&emsp;value\. If an ``` inf ``` or ``` NaN ``` is passed in, it will not signal, and the resulting floating point  
&emsp;&emsp;value is unspecified\. Otherwise, the bit\-level representation is preserved\.  
  
### isinf\(\) function  
#### <code>glm.<code>**isinf**(**x**: *float*) -\> *bool*</code></code>  
&emsp;&emsp;Returns ``` True ``` if ``` x ``` holds a positive infinity or negative infinity representation in the  
&emsp;&emsp;underlying implementation's set of floating point representations\.  
&emsp;&emsp;Returns ``` False ``` otherwise, including for implementations with no infinity representations\.  
  
#### <code>glm.<code>**isinf**(**x**: *vecN*) -\> *bvecN*</code></code>  
&emsp;&emsp;Returns ``` True ``` if ``` x ``` holds a positive infinity or negative infinity representation in the  
&emsp;&emsp;underlying implementation's set of floating point representations\.  
&emsp;&emsp;Returns ``` False ``` otherwise, including for implementations with no infinity representations\.  
  
#### <code>glm.<code>**isinf**(**x**: *quat*) -\> *bvecN*</code></code>  
&emsp;&emsp;Returns ``` True ``` if ``` x ``` holds a positive infinity or negative infinity representation in the  
&emsp;&emsp;underlying implementation's set of floating point representations\.  
&emsp;&emsp;Returns ``` False ``` otherwise, including for implementations with no infinity representations\.  
  
### isnan\(\) function  
#### <code>glm.<code>**isnan**(**x**: *float*) -\> *bool*</code></code>  
&emsp;&emsp;Returns ``` True ``` if ``` x ``` holds a ``` NaN ``` \(not a number\) representation in the underlying  
&emsp;&emsp;implementation's set of floating point representations\.  
&emsp;&emsp;Returns ``` False ``` otherwise, including for implementations with no ``` NaN ``` representations\.  
  
#### <code>glm.<code>**isnan**(**x**: *vecN*) -\> *bvecN*</code></code>  
&emsp;&emsp;Returns ``` True ``` if ``` x ``` holds a ``` NaN ``` \(not a number\) representation in the underlying  
&emsp;&emsp;implementation's set of floating point representations\.  
&emsp;&emsp;Returns ``` False ``` otherwise, including for implementations with no ``` NaN ``` representations\.  
  
#### <code>glm.<code>**isnan**(**x**: *quat*) -\> *bvecN*</code></code>  
&emsp;&emsp;Returns ``` True ``` if ``` x ``` holds a ``` NaN ``` \(not a number\) representation in the underlying  
&emsp;&emsp;implementation's set of floating point representations\.  
&emsp;&emsp;Returns ``` False ``` otherwise, including for implementations with no ``` NaN ``` representations\.  
  
### ldexp\(\) function  
#### <code>glm.<code>**ldexp**(**x**: *number*, **exp**: *int*) -\> *float*</code></code>  
&emsp;&emsp;Builds a floating\-point number from ``` x ``` and the corresponding integral exponent of two in  
&emsp;&emsp;``` exp ```, returning: ``` significand * exp(2, exponent) ```\. If this product is too large to be  
&emsp;&emsp;represented in the floating\-point type, the result is undefined\.  
  
#### <code>glm.<code>**ldexp**(**x**: *vecN*, **exp**: *ivecN*) -\> *vecN*</code></code>  
&emsp;&emsp;Builds a floating\-point number from ``` x ``` and the corresponding integral exponent of two in  
&emsp;&emsp;``` exp ```, returning: ``` significand * exp(2, exponent) ```\. If this product is too large to be  
&emsp;&emsp;represented in the floating\-point type, the result is undefined\.  
  
### max\(\) function  
#### <code>glm.<code>**max**(**x**: *number*, **y**: *number*) -\> *float*</code></code>  
&emsp;&emsp;Returns ``` y ``` if ``` x < y ```; otherwise, it returns ``` x ```\.  
  
#### <code>glm.<code>**max**(**x**: *vecN*, **y**: *number*) -\> *vecN*</code></code>  
&emsp;&emsp;Returns ``` y ``` if ``` x < y ```; otherwise, it returns ``` x ```\.  
  
#### <code>glm.<code>**max**(**x**: *vecN*, **y**: *vecN*) -\> *vecN*</code></code>  
&emsp;&emsp;Returns ``` y ``` if ``` x < y ```; otherwise, it returns ``` x ```\.  
  
#### <code>glm.<code>**max**(**a**: *number*, **b**: *number*, **c**: *number*) -\> *float*</code></code>  
&emsp;&emsp;Returns the maximum value of 3 inputs\.  
  
#### <code>glm.<code>**max**(**a**: *vecN*, **b**: *vecN*, **c**: *vecN*) -\> *vecN*</code></code>  
&emsp;&emsp;Returns the maximum component wise value of 3 inputs\.  
  
#### <code>glm.<code>**max**(**a**: *number*, **b**: *number*, **c**: *number*, **d**: *number*) -\> *float*</code></code>  
&emsp;&emsp;Returns the maximum value of 4 inputs\.  
  
#### <code>glm.<code>**max**(**a**: *vecN*, **b**: *vecN*, **c**: *vecN*, **d**: *vecN*) -\> *vecN*</code></code>  
&emsp;&emsp;Returns the maximum component wise value of 4 inputs\.  
  
#### <code>glm.<code>**max**(**iterable**) -\> *any*</code></code>  
&emsp;&emsp;Returns the greatest number or the maximum component wise value respectively\.  
  
### min\(\) function  
#### <code>glm.<code>**min**(**x**: *number*, **y**: *number*) -\> *float*</code></code>  
&emsp;&emsp;Returns ``` y ``` if ``` y < x ```; otherwise, it returns ``` x ```\.  
  
#### <code>glm.<code>**min**(**x**: *vecN*, **y**: *number*) -\> *vecN*</code></code>  
&emsp;&emsp;Returns ``` y ``` if ``` y < x ```; otherwise, it returns ``` x ```\.  
  
#### <code>glm.<code>**min**(**x**: *vecN*, **y**: *vecN*) -\> *vecN*</code></code>  
&emsp;&emsp;Returns ``` y ``` if ``` y < x ```; otherwise, it returns ``` x ```\.  
  
#### <code>glm.<code>**min**(**a**: *number*, **b**: *number*, **c**: *number*) -\> *float*</code></code>  
&emsp;&emsp;Returns the minimum value of 3 inputs\.  
  
#### <code>glm.<code>**min**(**a**: *vecN*, **b**: *vecN*, **c**: *vecN*) -\> *vecN*</code></code>  
&emsp;&emsp;Returns the minimum component wise value of 3 inputs\.  
  
#### <code>glm.<code>**min**(**a**: *number*, **b**: *number*, **c**: *number*, **d**: *number*) -\> *float*</code></code>  
&emsp;&emsp;Returns the minimum value of 4 inputs\.  
  
#### <code>glm.<code>**min**(**a**: *vecN*, **b**: *vecN*, **c**: *vecN*, **d**: *vecN*) -\> *vecN*</code></code>  
&emsp;&emsp;Returns the minimum component wise value of 4 inputs\.  
  
#### <code>glm.<code>**min**(**iterable**) -\> *any*</code></code>  
&emsp;&emsp;Returns the smallest number or the minimum component wise value respectively\.  
  
### mix\(\) function  
#### <code>glm.<code>**mix**(**x**: *number*, **y**: *number*, **a**: *float*) -\> *number*</code></code>  
&emsp;&emsp;Returns ``` x * (1.0 - a) + y * a ```, i\.e\., the linear blend of ``` x ``` and ``` y ``` using the floating\-point  
&emsp;&emsp;value ``` a ```\. The value for ``` a ``` is not restricted to the range ``` [0, 1] ```\.  
  
#### <code>glm.<code>**mix**(**x**: *number*, **y**: *number*, **a**: *bool*) -\> *number*</code></code>  
&emsp;&emsp;Returns ``` y ``` if ``` a ``` is ``` True ``` and ``` x ``` otherwise\.  
  
#### <code>glm.<code>**mix**(**x**: *vecN*, **y**: *vecN*, **a**: *fvecN*) -\> *vecN*</code></code>  
&emsp;&emsp;Returns ``` x * (1.0 - a) + y * a ```, i\.e\., the linear blend of ``` x ``` and ``` y ``` using the floating\-point  
&emsp;&emsp;value ``` a ```\. The value for ``` a ``` is not restricted to the range ``` [0, 1] ```\.  
  
#### <code>glm.<code>**mix**(**x**: *vecN*, **y**: *vecN*, **a**: *bvecN*) -\> *vecN*</code></code>  
&emsp;&emsp;For each component index ``` i ```:  
&emsp;&emsp;Returns ``` y[i] ``` if ``` a[i] ``` is ``` True ``` and ``` x[i] ``` otherwise\.  
  
#### <code>glm.<code>**mix**(**x**: *matNxM*, **y**: *matNxM*, **a**: *fmatNxM*) -\> *matNxM*</code></code>  
&emsp;&emsp;Returns ``` x * (1.0 - a) + y * a ```, i\.e\., the linear blend of ``` x ``` and ``` y ``` using the floating\-point  
&emsp;&emsp;value ``` a ``` for each component\. The value for ``` a ``` is not restricted to the range ``` [0, 1] ```\.  
  
#### <code>glm.<code>**mix**(**x**: *matNxM*, **y**: *matNxM*, **a**: *float*) -\> *matNxM*</code></code>  
&emsp;&emsp;Returns ``` x * (1.0 - a) + y * a ```, i\.e\., the linear blend of ``` x ``` and ``` y ``` using the floating\-point  
&emsp;&emsp;value ``` a ``` for each component\. The value for ``` a ``` is not restricted to the range ``` [0, 1] ```\.  
  
#### <code>glm.<code>**mix**(**x**: *quat*, **y**: *quat*, **a**: *float*) -\> *quat*</code></code>  
&emsp;&emsp;Spherical linear interpolation of two quaternions\. The interpolation is oriented and the  
&emsp;&emsp;rotation is performed at constant speed\. For short path spherical linear interpolation, use  
&emsp;&emsp;the ``` slerp ``` function\.  
  
### mod\(\) function  
#### <code>glm.<code>**mod**(**a**, **b**) -\> *Any*</code></code>  
&emsp;&emsp;Equivalent to ``` a % b ```\.  
  
### modf\(\) function  
#### <code>glm.<code>**modf**(**x**: *float*) -\> *(fraction, integer)*</code></code>  
&emsp;&emsp;Returns the fractional part of ``` x ``` and the integer part \(as a whole number floating point value\)\.  
  
#### <code>glm.<code>**modf**(**x**: *vecN*, **i**: *vecN*) -\> *vecN*</code></code>  
&emsp;&emsp;Returns the fractional part of ``` x ``` and sets ``` i ``` to the integer part \(as a whole number floating  
&emsp;&emsp;point value\)\.  
  
### round\(\) function  
#### <code>glm.<code>**round**(**x**: *number*) -\> *float*</code></code>  
&emsp;&emsp;Returns a value equal to the nearest integer to ``` x ```\. The fraction ``` 0.5 ``` will round in a  
&emsp;&emsp;direction chosen by the implementation, presumably the direction that is fastest\. This  
&emsp;&emsp;includes the possibility that ``` round(x) ``` returns the same value as ``` roundEven(x) ```  
  
#### <code>glm.<code>**round**(**x**: *vecN*) -\> *vecN*</code></code>  
&emsp;&emsp;Returns a value equal to the nearest integer to ``` x ```\. The fraction ``` 0.5 ``` will round in a  
&emsp;&emsp;direction chosen by the implementation, presumably the direction that is fastest\. This  
&emsp;&emsp;includes the possibility that ``` round(x) ``` returns the same value as ``` roundEven(x) ``` for all  
&emsp;&emsp;values of ``` x ```\.  
  
### roundEven\(\) function  
#### <code>glm.<code>**roundEven**(**x**: *number*) -\> *float*</code></code>  
&emsp;&emsp;Returns a value equal to the nearest integer to ``` x ```\. A fractional part of ``` 0.5 ``` will round  
&emsp;&emsp;toward the nearest even integer\. \(Both ``` 3.5 ``` and ``` 4.5 ``` for ``` x ``` will return ``` 4.0 ```\.\)  
  
#### <code>glm.<code>**roundEven**(**x**: *vecN*) -\> *vecN*</code></code>  
&emsp;&emsp;Returns a value equal to the nearest integer to ``` x ```\. A fractional part of ``` 0.5 ``` will round  
&emsp;&emsp;toward the nearest even integer\. \(Both ``` 3.5 ``` and ``` 4.5 ``` for ``` x ``` will return ``` 4.0 ```\.\)  
  
### sign\(\) function  
#### <code>glm.<code>**sign**(**x**: *number*) -\> *float*</code></code>  
&emsp;&emsp;Returns ``` 1.0 ``` if ``` x > 0 ```, ``` 0.0 ``` if ``` x == 0 ```, or ``` -1.0 ``` if ``` x < 0 ```\.  
  
#### <code>glm.<code>**sign**(**x**: *vecN*) -\> *vecN*</code></code>  
&emsp;&emsp;For every component ``` c ``` of ``` x ```:  
&emsp;&emsp;Returns ``` 1.0 ``` if ``` x > 0 ```, ``` 0.0 ``` if ``` x == 0 ```, or ``` -1.0 ``` if ``` x < 0 ```\.  
  
### smoothstep\(\) function  
#### <code>glm.<code>**smoothstep**(**edge0**: *number*, **edge1**: *number*, **x**: *number*) -\> *float*</code></code>  
&emsp;&emsp;Returns ``` 0.0 ``` if ``` x <= edge0 ``` and ``` 1.0 ``` if ``` x >= edge1 ``` and performs smooth Hermite interpolation  
&emsp;&emsp;between ``` 0 ``` and ``` 1 ``` when ``` edge0 < x < edge1 ```\. This is useful in cases where you would want a  
&emsp;&emsp;threshold function with a smooth transition\. This is equivalent to :  
&emsp;&emsp;``` t = clamp((x - edge0) / (edge1 - edge0), 0, 1) ```  
&emsp;&emsp;``` return t * t * (3 - 2 * t) ```  
&emsp;&emsp;Results are undefined if ``` edge0 >= edge1 ```\.  
  
#### <code>glm.<code>**smoothstep**(**edge0**: *number*, **edge1**: *number*, **x**: *vecN*) -\> *vecN*</code></code>  
&emsp;&emsp;Returns ``` 0.0 ``` if ``` x <= edge0 ``` and ``` 1.0 ``` if ``` x >= edge1 ``` and performs smooth Hermite interpolation  
&emsp;&emsp;between ``` 0 ``` and ``` 1 ``` when ``` edge0 < x < edge1 ```\. This is useful in cases where you would want a  
&emsp;&emsp;threshold function with a smooth transition\. This is equivalent to :  
&emsp;&emsp;``` t = clamp((x - edge0) / (edge1 - edge0), 0, 1) ```  
&emsp;&emsp;``` return t * t * (3 - 2 * t) ```  
&emsp;&emsp;Results are undefined if ``` edge0 >= edge1 ```\.  
  
#### <code>glm.<code>**smoothstep**(**edge0**: *vecN*, **edge1**: *vecN*, **x**: *vecN*) -\> *vecN*</code></code>  
&emsp;&emsp;Returns ``` 0.0 ``` if ``` x <= edge0 ``` and ``` 1.0 ``` if ``` x >= edge1 ``` and performs smooth Hermite interpolation  
&emsp;&emsp;between ``` 0 ``` and ``` 1 ``` when ``` edge0 < x < edge1 ```\. This is useful in cases where you would want a  
&emsp;&emsp;threshold function with a smooth transition\. This is equivalent to :  
&emsp;&emsp;``` t = clamp((x - edge0) / (edge1 - edge0), 0, 1) ```  
&emsp;&emsp;``` return t * t * (3 - 2 * t) ```  
&emsp;&emsp;Results are undefined if ``` edge0 >= edge1 ```\.  
  
### step\(\) function  
#### <code>glm.<code>**step**(**edge**: *number*, **x**: *number*) -\> *float*</code></code>  
&emsp;&emsp;Returns ``` 0.0 ``` if ``` x < edge ```, otherwise it returns ``` 1.0 ```\.  
  
#### <code>glm.<code>**step**(**edge**: *number*, **x**: *vecN*) -\> *vecN*</code></code>  
&emsp;&emsp;For every component ``` c ``` of ``` x ```:  
&emsp;&emsp;Returns ``` 0.0 ``` if ``` c < edge ```, otherwise it returns ``` 1.0 ```\.  
  
#### <code>glm.<code>**step**(**edge**: *vecN*, **x**: *vecN*) -\> *vecN*</code></code>  
&emsp;&emsp;For every index ``` i ```:  
&emsp;&emsp;Returns ``` 0.0 ``` if ``` x[i] < edge[i] ```, otherwise it returns ``` 1.0 ```\.  
  
### trunc\(\) function  
#### <code>glm.<code>**trunc**(**x**: *number*) -\> *float*</code></code>  
&emsp;&emsp;Returns a value equal to the nearest integer to ``` x ``` whose absolute value is not larger than  
&emsp;&emsp;the absolute value of ``` x ```\.  
  
#### <code>glm.<code>**trunc**(**x**: *vecN*) -\> *vecN*</code></code>  
&emsp;&emsp;For every component ``` c ``` of ``` x ```:  
&emsp;&emsp;Returns a value equal to the nearest integer to ``` c ``` whose absolute value is not larger than  
&emsp;&emsp;the absolute value of ``` c ```\.  
  
### uintBitsToFloat\(\) function  
#### <code>glm.<code>**uintBitsToFloat**(**v**: *int*) -\> *float*</code></code>  
&emsp;&emsp;Returns a floating\-point value corresponding to an unsigned integer encoding of a floating\-point  
&emsp;&emsp;value\. If an ``` inf ``` or ``` NaN ``` is passed in, it will not signal, and the resulting floating point  
&emsp;&emsp;value is unspecified\. Otherwise, the bit\-level representation is preserved\.  
  
#### <code>glm.<code>**uintBitsToFloat**(**v**: *ivecN*) -\> *fvecN*</code></code>  
&emsp;&emsp;Returns a floating\-point value corresponding to an unsigned integer encoding of a floating\-point  
&emsp;&emsp;value\. If an ``` inf ``` or ``` NaN ``` is passed in, it will not signal, and the resulting floating point  
&emsp;&emsp;value is unspecified\. Otherwise, the bit\-level representation is preserved\.  
  
