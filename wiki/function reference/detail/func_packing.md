[//]: # (generated using SlashBack 0.2.0)

  
# func\_packing methods  
The following methods are all part of the **func\_packing methods**\.  
Provides GLSL functions to pack and unpack half, single and double\-precision floating point values into more compact integer types\.  
## Table of contents  
  
* [**packDouble2x32** function](#packdouble2x32-function)  
* [**packHalf2x16** function](#packhalf2x16-function)  
* [**packSnorm2x16** function](#packsnorm2x16-function)  
* [**packSnorm4x8** function](#packsnorm4x8-function)  
* [**packUnorm2x16** function](#packunorm2x16-function)  
* [**packUnorm4x8** function](#packunorm4x8-function)  
* [**unpackDouble2x32** function](#unpackdouble2x32-function)  
* [**unpackHalf2x16** function](#unpackhalf2x16-function)  
* [**unpackSnorm2x16** function](#unpacksnorm2x16-function)  
* [**unpackSnorm4x8** function](#unpacksnorm4x8-function)  
* [**unpackUnorm2x16** function](#unpackunorm2x16-function)  
* [**unpackUnorm4x8** function](#unpackunorm4x8-function)  
  
### packDouble2x32\(\) function  
#### <code>glm.<code>**packDouble2x32**(**v**: *uvec2*) -\> *float*</code></code>  
&emsp;&emsp;Returns a double\-qualifier value obtained by packing the components of v into a 64\-bit  
&emsp;&emsp;value\. If an IEEE 754 Inf or NaN is created, it will not signal, and the resulting floating  
&emsp;&emsp;point value is unspecified\.Otherwise, the bit \- level representation of v is preserved\. The  
&emsp;&emsp;first vector component specifies the 32 least significant bits; the second component  
&emsp;&emsp;specifies the 32 most significant bits\.  
  
### packHalf2x16\(\) function  
#### <code>glm.<code>**packHalf2x16**(**v**: *vec2*) -\> *int*</code></code>  
&emsp;&emsp;Returns an unsigned integer obtained by converting the components of a two\-component  
&emsp;&emsp;floating\-point vector to the 16\-bit floating\-point representation found in the OpenGL  
&emsp;&emsp;Specification, and then packing these two 16\- bit integers into a 32\-bit unsigned integer\.  
&emsp;&emsp;The first vector component specifies the 16 least \- significant bits of the result; the  
&emsp;&emsp;second component specifies the 16 most \- significant bits\.  
  
### packSnorm2x16\(\) function  
#### <code>glm.<code>**packSnorm2x16**(**v**: *vec2*) -\> *int*</code></code>  
&emsp;&emsp;First, converts each component of the normalized floating\-point value v into 8\- or 16\-bit  
&emsp;&emsp;integer values\. Then, the results are packed into the returned 32 \- bit unsigned integer\.  
&emsp;&emsp;The conversion for component c of v to fixed point is done as follows : packSnorm2x16:   
&emsp;&emsp;round\(clamp\(v, \-1, \+1\) \* 32767\.0\)\. The first component of the vector will be written to  
&emsp;&emsp;the least significant bits of the output; the last component will be written to the most  
&emsp;&emsp;significant bits\.  
  
### packSnorm4x8\(\) function  
#### <code>glm.<code>**packSnorm4x8**(**v**: *vec4*) -\> *int*</code></code>  
&emsp;&emsp;First, converts each component of the normalized floating\-point value v into 8\- or 16\-bit  
&emsp;&emsp;integer values\. Then, the results are packed into the returned 32 \- bit unsigned integer\.  
&emsp;&emsp;The conversion for component c of v to fixed point is done as follows : packSnorm4x8:  
&emsp;&emsp;round\(clamp\(c, \-1, \+1\) \* 127\.0\)\. The first component of the vector will be written to  
&emsp;&emsp;the least significant bits of the output; the last component will be written to the most  
&emsp;&emsp;significant bits\.  
  
### packUnorm2x16\(\) function  
#### <code>glm.<code>**packUnorm2x16**(**v**: *vec2*) -\> *int*</code></code>  
&emsp;&emsp;First, converts each component of the normalized floating\-point value v into 8\- or 16\-bit  
&emsp;&emsp;integer values\. Then, the results are packed into the returned 32 \- bit unsigned integer\.  
&emsp;&emsp;The conversion for component c of v to fixed point is done as follows : packUnorm2x16:  
&emsp;&emsp;round\(clamp\(c, 0, \+1\) \* 65535\.0\)\. The first component of the vector will be written to the  
&emsp;&emsp;least significant bits of the output; the last component will be written to the most  
&emsp;&emsp;significant bits\.  
  
### packUnorm4x8\(\) function  
#### <code>glm.<code>**packUnorm4x8**(**v**: *vec4*) -\> *int*</code></code>  
&emsp;&emsp;First, converts each component of the normalized floating\-point value v into 8\- or 16\-bit  
&emsp;&emsp;integer values\. Then, the results are packed into the returned 32 \- bit unsigned integer\.  
&emsp;&emsp;The conversion for component c of v to fixed point is done as follows : packUnorm4x8:  
&emsp;&emsp;round\(clamp\(c, 0, \+1\) \* 255\.0\)\. The first component of the vector will be written to the  
&emsp;&emsp;least significant bits of the output; the last component will be written to the most  
&emsp;&emsp;significant bits\.  
  
### unpackDouble2x32\(\) function  
#### <code>glm.<code>**unpackDouble2x32**(**v**: *double*) -\> *uvec2*</code></code>  
&emsp;&emsp;Returns a two\-component unsigned integer vector representation of v\. The bit \- level  
&emsp;&emsp;representation of v is preserved\.The first component of the vector contains the 32 least  
&emsp;&emsp;significant bits of the double; the second component consists the 32 most significant bits\.  
  
### unpackHalf2x16\(\) function  
#### <code>glm.<code>**unpackHalf2x16**(**v**: *int*) -\> *vec2*</code></code>  
&emsp;&emsp;Returns a two\-component floating\-point vector with components obtained by unpacking a  
&emsp;&emsp;32\-bit unsigned integer into a pair of 16\-bit values, interpreting those values as 16\-bit  
&emsp;&emsp;floating\-point numbers according to the OpenGL Specification, and converting them to 32\-bit  
&emsp;&emsp;floating\-point values\. The first component of the vector is obtained from the 16  
&emsp;&emsp;least \- significant bits of v; the second component is obtained from the 16  
&emsp;&emsp;most \- significant bits of v\.  
  
### unpackSnorm2x16\(\) function  
#### <code>glm.<code>**unpackSnorm2x16**(**p**: *int*) -\> *vec2*</code></code>  
&emsp;&emsp;First, unpacks a single 32\-bit unsigned integer p into a pair of 16\-bit unsigned integers,  
&emsp;&emsp;four 8\-bit unsigned integers, or four 8\-bit signed integers\. Then, each component is  
&emsp;&emsp;converted to a normalized floating \- point value to generate the returned two\- or  
&emsp;&emsp;four\-component vector\. The conversion for unpacked fixed \- point value f to floating point  
&emsp;&emsp;is done as follows : unpackSnorm2x16: clamp\(f / 32767\.0, \-1, \+1\)\. The first component of  
&emsp;&emsp;the returned vector will be extracted from the least significant bits of the input; the  
&emsp;&emsp;last component will be extracted from the most significant bits\.  
  
### unpackSnorm4x8\(\) function  
#### <code>glm.<code>**unpackSnorm4x8**(**p**: *int*) -\> *vec4*</code></code>  
&emsp;&emsp;First, unpacks a single 32\-bit unsigned integer p into a pair of 16\-bit unsigned integers,  
&emsp;&emsp;four 8\-bit unsigned integers, or four 8\-bit signed integers\. Then, each component is  
&emsp;&emsp;converted to a normalized floating \- point value to generate the returned two\- or  
&emsp;&emsp;four\-component vector\. The conversion for unpacked fixed \- point value f to floating point  
&emsp;&emsp;is done as follows : unpackSnorm4x8: clamp\(f / 127\.0, \-1, \+1\)\. The first component of the  
&emsp;&emsp;returned vector will be extracted from the least significant bits of the input; the last  
&emsp;&emsp;component will be extracted from the most significant bits\.  
  
### unpackUnorm2x16\(\) function  
#### <code>glm.<code>**unpackUnorm2x16**(**p**: *int*) -\> *vec2*</code></code>  
&emsp;&emsp;First, unpacks a single 32\-bit unsigned integer p into a pair of 16\-bit unsigned integers,  
&emsp;&emsp;four 8\-bit unsigned integers, or four 8\-bit signed integers\. Then, each component is  
&emsp;&emsp;converted to a normalized floating \- point value to generate the returned two\- or  
&emsp;&emsp;four\-component vector\. The conversion for unpacked fixed \- point value f to floating point  
&emsp;&emsp;is done as follows : unpackUnorm2x16: f / 65535\.0\. The first component of the returned  
&emsp;&emsp;vector will be extracted from the least significant bits of the input; the last component  
&emsp;&emsp;will be extracted from the most significant bits\.  
  
### unpackUnorm4x8\(\) function  
#### <code>glm.<code>**unpackUnorm4x8**(**p**: *int*) -\> *vec4*</code></code>  
&emsp;&emsp;First, unpacks a single 32\-bit unsigned integer p into a pair of 16\-bit unsigned integers,  
&emsp;&emsp;four 8\-bit unsigned integers, or four 8\-bit signed integers\. Then, each component is  
&emsp;&emsp;converted to a normalized floating \- point value to generate the returned two\- or  
&emsp;&emsp;four\-component vector\. The conversion for unpacked fixed \- point value f to floating point  
&emsp;&emsp;is done as follows : unpackUnorm4x8: f / 255\.0\. The first component of the returned vector  
&emsp;&emsp;will be extracted from the least significant bits of the input; the last component will be  
&emsp;&emsp;extracted from the most significant bits\.  
  
