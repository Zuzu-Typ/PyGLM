[//]: # (generated using SlashBack 0.2.0)

  
# packing methods  
The following methods are all part of the **packing methods**\.  
This extension provides a set of function to convert vertors to packed formats\.  
## Table of contents  
  
* [**packF2x11\_1x10** function](#packf2x11_1x10-function)  
* [**packF3x9\_E1x5** function](#packf3x9_e1x5-function)  
* [**packHalf** function](#packhalf-function)  
* [**packHalf1x16** function](#packhalf1x16-function)  
* [**packHalf4x16** function](#packhalf4x16-function)  
* [**packI3x10\_1x2** function](#packi3x10_1x2-function)  
* [**packInt2x16** function](#packint2x16-function)  
* [**packInt2x32** function](#packint2x32-function)  
* [**packInt2x8** function](#packint2x8-function)  
* [**packInt4x16** function](#packint4x16-function)  
* [**packInt4x8** function](#packint4x8-function)  
* [**packRGBM** function](#packrgbm-function)  
* [**packSnorm** function](#packsnorm-function)  
* [**packSnorm1x16** function](#packsnorm1x16-function)  
* [**packSnorm1x8** function](#packsnorm1x8-function)  
* [**packSnorm2x8** function](#packsnorm2x8-function)  
* [**packSnorm3x10\_1x2** function](#packsnorm3x10_1x2-function)  
* [**packSnorm4x16** function](#packsnorm4x16-function)  
* [**packU3x10\_1x2** function](#packu3x10_1x2-function)  
* [**packUint2x16** function](#packuint2x16-function)  
* [**packUint2x32** function](#packuint2x32-function)  
* [**packUint2x8** function](#packuint2x8-function)  
* [**packUint4x16** function](#packuint4x16-function)  
* [**packUint4x8** function](#packuint4x8-function)  
* [**packUnorm** function](#packunorm-function)  
* [**packUnorm1x16** function](#packunorm1x16-function)  
* [**packUnorm1x5\_1x6\_1x5** function](#packunorm1x5_1x6_1x5-function)  
* [**packUnorm1x8** function](#packunorm1x8-function)  
* [**packUnorm2x3\_1x2** function](#packunorm2x3_1x2-function)  
* [**packUnorm2x4** function](#packunorm2x4-function)  
* [**packUnorm2x8** function](#packunorm2x8-function)  
* [**packUnorm3x10\_1x2** function](#packunorm3x10_1x2-function)  
* [**packUnorm3x5\_1x1** function](#packunorm3x5_1x1-function)  
* [**packUnorm4x16** function](#packunorm4x16-function)  
* [**packUnorm4x4** function](#packunorm4x4-function)  
* [**unpackF2x11\_1x10** function](#unpackf2x11_1x10-function)  
* [**unpackF3x9\_E1x5** function](#unpackf3x9_e1x5-function)  
* [**unpackHalf** function](#unpackhalf-function)  
* [**unpackHalf1x16** function](#unpackhalf1x16-function)  
* [**unpackHalf4x16** function](#unpackhalf4x16-function)  
* [**unpackI3x10\_1x2** function](#unpacki3x10_1x2-function)  
* [**unpackInt2x16** function](#unpackint2x16-function)  
* [**unpackInt2x32** function](#unpackint2x32-function)  
* [**unpackInt2x8** function](#unpackint2x8-function)  
* [**unpackInt4x16** function](#unpackint4x16-function)  
* [**unpackInt4x8** function](#unpackint4x8-function)  
* [**unpackRGBM** function](#unpackrgbm-function)  
* [**unpackSnorm** function](#unpacksnorm-function)  
* [**unpackSnorm1x16** function](#unpacksnorm1x16-function)  
* [**unpackSnorm1x8** function](#unpacksnorm1x8-function)  
* [**unpackSnorm2x8** function](#unpacksnorm2x8-function)  
* [**unpackSnorm3x10\_1x2** function](#unpacksnorm3x10_1x2-function)  
* [**unpackSnorm4x16** function](#unpacksnorm4x16-function)  
* [**unpackU3x10\_1x2** function](#unpacku3x10_1x2-function)  
* [**unpackUint2x16** function](#unpackuint2x16-function)  
* [**unpackUint2x32** function](#unpackuint2x32-function)  
* [**unpackUint2x8** function](#unpackuint2x8-function)  
* [**unpackUint4x16** function](#unpackuint4x16-function)  
* [**unpackUint4x8** function](#unpackuint4x8-function)  
* [**unpackUnorm** function](#unpackunorm-function)  
* [**unpackUnorm1x16** function](#unpackunorm1x16-function)  
* [**unpackUnorm1x5\_1x6\_1x5** function](#unpackunorm1x5_1x6_1x5-function)  
* [**unpackUnorm1x8** function](#unpackunorm1x8-function)  
* [**unpackUnorm2x3\_1x2** function](#unpackunorm2x3_1x2-function)  
* [**unpackUnorm2x4** function](#unpackunorm2x4-function)  
* [**unpackUnorm2x8** function](#unpackunorm2x8-function)  
* [**unpackUnorm3x10\_1x2** function](#unpackunorm3x10_1x2-function)  
* [**unpackUnorm3x5\_1x1** function](#unpackunorm3x5_1x1-function)  
* [**unpackUnorm4x16** function](#unpackunorm4x16-function)  
* [**unpackUnorm4x4** function](#unpackunorm4x4-function)  
  
### packF2x11\_1x10\(\) function  
#### <code>glm.<code>**packF2x11_1x10**(**v**: *vec3*) -\> *int*</code></code>  
&emsp;&emsp;First, converts the first two components of the normalized floating\-point value ``` v ``` into  
&emsp;&emsp;11\-bit signless floating\-point values\. Then, converts the third component of the normalized  
&emsp;&emsp;floating\-point value ``` v ``` into a 10\-bit signless floating\-point value\. Then, the results  
&emsp;&emsp;are packed into the returned 32\-bit unsigned integer\. The first vector component  
&emsp;&emsp;specifies the 11 least\-significant bits of the result; the last component specifies the  
&emsp;&emsp;10 most\-significant bits\.  
  
### packF3x9\_E1x5\(\) function  
#### <code>glm.<code>**packF3x9_E1x5**(**v**: *vec3*) -\> *int*</code></code>  
&emsp;&emsp;First, converts the first two components of the normalized floating\-point value ``` v ``` into  
&emsp;&emsp;11\-bit signless floating\-point values\. Then, converts the third component of the normalized  
&emsp;&emsp;floating\-point value ``` v ``` into a 10\-bit signless floating\-point value\.Then, the results  
&emsp;&emsp;are packed into the returned 32\-bit unsigned integer\. The first vector component  
&emsp;&emsp;specifies the 11 least\-significant bits of the result; the last component specifies the  
&emsp;&emsp;10 most\-significant bits\. packF3x9\_E1x5 allows encoding into RGBE / RGB9E5 format  
  
### packHalf\(\) function  
#### <code>glm.<code>**packHalf**(**v**: *vecN*) -\> *u16vecN*</code></code>  
&emsp;&emsp;Returns an unsigned integer vector obtained by converting the components of a  
&emsp;&emsp;floating\-point vector to the 16\-bit floating\-point representation found in the OpenGL  
&emsp;&emsp;Specification\. The first vector component specifies the 16 least\-significant bits of the  
&emsp;&emsp;result; the forth component specifies the 16 most\-significant bits\.  
  
### packHalf1x16\(\) function  
#### <code>glm.<code>**packHalf1x16**(**v**: *float*) -\> *int*</code></code>  
&emsp;&emsp;Returns an unsigned integer obtained by converting the components of a floating\-point  
&emsp;&emsp;scalar to the 16\-bit floating\-point representation found in the OpenGL Specification, and  
&emsp;&emsp;then packing this 16\-bit value into a 16\-bit unsigned integer\.  
  
### packHalf4x16\(\) function  
#### <code>glm.<code>**packHalf4x16**(**v**: *vec4*) -\> *int*</code></code>  
&emsp;&emsp;Returns an unsigned integer obtained by converting the components of a four\-component  
&emsp;&emsp;floating\-point vector to the 16\-bit floating\-point representation found in the OpenGL  
&emsp;&emsp;Specification, and then packing these four 16\-bit values into a 64\-bit unsigned integer\.  
&emsp;&emsp;The first vector component specifies the 16 least\-significant bits of the result; the  
&emsp;&emsp;forth component specifies the 16 most\-significant bits\.  
  
### packI3x10\_1x2\(\) function  
#### <code>glm.<code>**packI3x10_1x2**(**v**: *ivec4*) -\> *int*</code></code>  
&emsp;&emsp;Returns an unsigned integer obtained by converting the components of a four\-component  
&emsp;&emsp;signed integer vector to the 10\-10\-10\-2\-bit signed integer representation found in the  
&emsp;&emsp;OpenGL Specification, and then packing these four values into a 32\-bit unsigned integer\.  
&emsp;&emsp;The first vector component specifies the 10 least\-significant bits of the result; the  
&emsp;&emsp;forth component specifies the 2 most\-significant bits\.  
  
### packInt2x16\(\) function  
#### <code>glm.<code>**packInt2x16**(**v**: *i16vec2*) -\> *int*</code></code>  
&emsp;&emsp;Convert each component from an integer vector into a packed integer\.  
  
### packInt2x32\(\) function  
#### <code>glm.<code>**packInt2x32**(**v**: *i32vec2*) -\> *int*</code></code>  
&emsp;&emsp;Convert each component from an integer vector into a packed integer\.  
  
### packInt2x8\(\) function  
#### <code>glm.<code>**packInt2x8**(**v**: *i8vec2*) -\> *int*</code></code>  
&emsp;&emsp;Convert each component from an integer vector into a packed integer\.  
  
### packInt4x16\(\) function  
#### <code>glm.<code>**packInt4x16**(**v**: *i16vec4*) -\> *int*</code></code>  
&emsp;&emsp;Convert each component from an integer vector into a packed integer\.  
  
### packInt4x8\(\) function  
#### <code>glm.<code>**packInt4x8**(**v**: *i8vec4*) -\> *int*</code></code>  
&emsp;&emsp;Convert each component from an integer vector into a packed integer\.  
  
### packRGBM\(\) function  
#### <code>glm.<code>**packRGBM**(**v**: *vec3*) -\> *vec4*</code></code>  
&emsp;&emsp;Returns an unsigned integer vector obtained by converting the components of a  
&emsp;&emsp;floating\-point vector to the 16\-bit floating\-point representation found in the OpenGL  
&emsp;&emsp;Specification\. The first vector component specifies the 16 least\-significant bits of the  
&emsp;&emsp;result; the forth component specifies the 16 most\-significant bits\.  
  
### packSnorm\(\) function  
#### <code>glm.<code>**packSnorm**(**t**: *type*, **v**: *vecN*) -\> *vecN*</code></code>  
&emsp;&emsp;Convert each component of the normalized floating\-point vector into signed integer values  
&emsp;&emsp;of type ``` t ```\.  
&emsp;&emsp;``` t ``` can be any of the 8 integer types \(``` glm.int32 ```, ``` glm.int64 ```, ``` glm.uint8 ```, \.\.\.\)\.  
  
### packSnorm1x16\(\) function  
#### <code>glm.<code>**packSnorm1x16**(**v**: *float*) -\> *int*</code></code>  
&emsp;&emsp;First, converts the normalized floating\-point value ``` v ``` into 16\-bit integer value\. Then, the  
&emsp;&emsp;results are packed into the returned 16\-bit unsigned integer\. The conversion to fixed point is  
&emsp;&emsp;done as follows : ``` round(clamp(s, -1, +1) * 32767.0) ```  
  
### packSnorm1x8\(\) function  
#### <code>glm.<code>**packSnorm1x8**(**v**: *float*) -\> *int*</code></code>  
&emsp;&emsp;First, converts the normalized floating\-point value ``` v ``` into 8\-bit integer value\. Then, the  
&emsp;&emsp;results are packed into the returned 8\-bit unsigned integer\. The conversion to fixed point is  
&emsp;&emsp;done as follows : ``` round(clamp(v, -1, +1) * 127.0) ```  
  
### packSnorm2x8\(\) function  
#### <code>glm.<code>**packSnorm2x8**(**v**: *fvec2*) -\> *int*</code></code>  
&emsp;&emsp;First, converts each component of the normalized floating\-point value ``` v ``` into 8\-bit integer  
&emsp;&emsp;values\. Then, the results are packed into the returned 16\-bit unsigned integer\. The  
&emsp;&emsp;conversion for component ``` c ``` of ``` v ``` to fixed point is done as follows :  
&emsp;&emsp;``` round(clamp(c, -1, +1) * 127.0) ```\. The first component of the vector will be  
&emsp;&emsp;written to the least significant bits of the output; the last component will be written to  
&emsp;&emsp;the most significant bits\.  
  
### packSnorm3x10\_1x2\(\) function  
#### <code>glm.<code>**packSnorm3x10_1x2**(**v**: *fvec4*) -\> *int*</code></code>  
&emsp;&emsp;First, converts the first three components of the normalized floating\-point value ``` v ``` into  
&emsp;&emsp;10\-bit signed integer values\. Then, converts the forth component of the normalized  
&emsp;&emsp;floating\-point value ``` v ``` into 2\-bit signed integer values\. Then, the results are packed into  
&emsp;&emsp;the returned 32\-bit unsigned integer\. The conversion for component c of v to fixed point  
&emsp;&emsp;is done as follows : ``` packSnorm3x10_1x2(xyz) ``` : ``` round(clamp(c, -1, +1) * 511.0) ```  
&emsp;&emsp;``` packSnorm3x10_1x2(w) ``` : ``` round(clamp(c, -1, +1) * 1.0) ```\. The first vector component specifies  
&emsp;&emsp;the 10 least\-significant bits of the result; the forth component specifies the 2  
&emsp;&emsp;most\-significant bits\.  
  
### packSnorm4x16\(\) function  
#### <code>glm.<code>**packSnorm4x16**(**v**: *fvec4*) -\> *int*</code></code>  
&emsp;&emsp;First, converts each component of the normalized floating\-point value ``` v ``` into 16\-bit integer  
&emsp;&emsp;values\. Then, the results are packed into the returned 64\-bit unsigned integer\. The  
&emsp;&emsp;conversion for component ``` c ``` of ``` v ``` to fixed point is done as follows :  
&emsp;&emsp;``` round(clamp(c, -1, +1) * 32767.0) ```\. The first component of the vector will be  
&emsp;&emsp;written to the least significant bits of the output; the last component will be written to  
&emsp;&emsp;the most significant bits\.  
  
### packU3x10\_1x2\(\) function  
#### <code>glm.<code>**packU3x10_1x2**(**v**: *uvec4*) -\> *int*</code></code>  
&emsp;&emsp;Returns an unsigned integer obtained by converting the components of a four\-component  
&emsp;&emsp;unsigned integer vector to the 10\-10\-10\-2\-bit unsigned integer representation found in the  
&emsp;&emsp;OpenGL Specification, and then packing these four values into a 32\-bit unsigned integer\.  
&emsp;&emsp;The first vector component specifies the 10 least\-significant bits of the result; the  
&emsp;&emsp;forth component specifies the 2 most\-significant bits\.  
  
### packUint2x16\(\) function  
#### <code>glm.<code>**packUint2x16**(**v**: *u16vec2*) -\> *int*</code></code>  
&emsp;&emsp;Convert each component from an integer vector into a packed unsigned integer\.  
  
### packUint2x32\(\) function  
#### <code>glm.<code>**packUint2x32**(**v**: *u32vec2*) -\> *int*</code></code>  
&emsp;&emsp;Convert each component from an integer vector into a packed unsigned integer\.  
  
### packUint2x8\(\) function  
#### <code>glm.<code>**packUint2x8**(**v**: *u8vec2*) -\> *int*</code></code>  
&emsp;&emsp;Convert each component from an integer vector into a packed unsigned integer\.  
  
### packUint4x16\(\) function  
#### <code>glm.<code>**packUint4x16**(**v**: *u16vec4*) -\> *int*</code></code>  
&emsp;&emsp;Convert each component from an integer vector into a packed unsigned integer\.  
  
### packUint4x8\(\) function  
#### <code>glm.<code>**packUint4x8**(**v**: *u16vec4*) -\> *int*</code></code>  
&emsp;&emsp;Convert each component from an integer vector into a packed unsigned integer\.  
  
### packUnorm\(\) function  
#### <code>glm.<code>**packUnorm**(**t**: *type*, **v**: *vecN*) -\> *vecN*</code></code>  
&emsp;&emsp;Convert each component of the normalized floating\-point vector into unsigned integer values  
&emsp;&emsp;of type ``` t ```\.  
&emsp;&emsp;``` t ``` can be any of the 4 unsigned integer types  
&emsp;&emsp;\(``` glm.uint64 ```, ``` glm.uint32 ```, ``` glm.uint16 ```, ``` glm.uint8 ```\)\.  
  
### packUnorm1x16\(\) function  
#### <code>glm.<code>**packUnorm1x16**(**v**: *float*) -\> *int*</code></code>  
&emsp;&emsp;First, converts the normalized floating\-point value ``` v ``` into a 16\-bit integer value\. Then,  
&emsp;&emsp;the results are packed into the returned 16\-bit unsigned integer\. The conversion for  
&emsp;&emsp;component ``` c ``` of ``` v ``` to fixed point is done as follows :  
&emsp;&emsp;``` round(clamp(c, 0, +1) * 65535.0) ```  
  
### packUnorm1x5\_1x6\_1x5\(\) function  
#### <code>glm.<code>**packUnorm1x5_1x6_1x5**(**v**: *fvec3*) -\> *int*</code></code>  
&emsp;&emsp;Convert each component of the normalized floating\-point vector into unsigned integer  
&emsp;&emsp;values\.  
  
### packUnorm1x8\(\) function  
#### <code>glm.<code>**packUnorm1x8**(**v**: *float*) -\> *int*</code></code>  
&emsp;&emsp;First, converts the normalized floating\-point value ``` v ``` into a 8\-bit integer value\. Then, the  
&emsp;&emsp;results are packed into the returned 8\-bit unsigned integer\. The conversion for component  
&emsp;&emsp;``` c ``` of ``` v ``` to fixed point is done as follows : ``` round(clamp(c, 0, +1) * 255.0) ```  
  
### packUnorm2x3\_1x2\(\) function  
#### <code>glm.<code>**packUnorm2x3_1x2**(**v**: *fvec3*) -\> *int*</code></code>  
&emsp;&emsp;Convert each component of the normalized floating\-point vector into unsigned integer  
&emsp;&emsp;values\.  
  
### packUnorm2x4\(\) function  
#### <code>glm.<code>**packUnorm2x4**(**v**: *fvec2*) -\> *int*</code></code>  
&emsp;&emsp;Convert each component of the normalized floating\-point vector into unsigned integer  
&emsp;&emsp;values\.  
  
### packUnorm2x8\(\) function  
#### <code>glm.<code>**packUnorm2x8**(**v**: *fvec2*) -\> *int*</code></code>  
&emsp;&emsp;First, converts each component of the normalized floating\-point value ``` v ``` into 8\-bit integer  
&emsp;&emsp;values\. Then, the results are packed into the returned 16\-bit unsigned integer\. The  
&emsp;&emsp;conversion for component ``` c ``` of ``` v ``` to fixed point is done as follows :  
&emsp;&emsp;``` round(clamp(c, 0, +1) * 255.0) ```\. The first component of the vector will be  
&emsp;&emsp;written to the least significant bits of the output; the last component will be written to  
&emsp;&emsp;the most significant bits\.  
  
### packUnorm3x10\_1x2\(\) function  
#### <code>glm.<code>**packUnorm3x10_1x2**(**v**: *fvec4*) -\> *int*</code></code>  
&emsp;&emsp;First, converts the first three components of the normalized floating\-point value ``` v ``` into  
&emsp;&emsp;10\-bit unsigned integer values\. Then, converts the forth component of the normalized  
&emsp;&emsp;floating\-point value ``` v ``` into 2\-bit signed uninteger values\.Then, the results are packed into  
&emsp;&emsp;the returned 32\-bit unsigned integer\. The conversion for component c of v to fixed point is  
&emsp;&emsp;done as follows : ``` packUnorm3x10_1x2(xyz) ``` : ``` round(clamp(c, 0, +1) * 1023.0) ```  
&emsp;&emsp;``` packUnorm3x10_1x2(w) ``` : ``` round(clamp(c, 0, +1) * 3.0) ```\. The first vector component specifies  
&emsp;&emsp;the 10 least\-significant bits of the result; the forth component specifies the 2  
&emsp;&emsp;most\-significant bits\.  
  
### packUnorm3x5\_1x1\(\) function  
#### <code>glm.<code>**packUnorm3x5_1x1**(**v**: *fvec4*) -\> *int*</code></code>  
&emsp;&emsp;Convert each component of the normalized floating\-point vector into unsigned integer  
&emsp;&emsp;values\.  
  
### packUnorm4x16\(\) function  
#### <code>glm.<code>**packUnorm4x16**(**v**: *fvec4*) -\> *int*</code></code>  
&emsp;&emsp;First, converts each component of the normalized floating\-point value ``` v ``` into 16\-bit integer  
&emsp;&emsp;values\. Then, the results are packed into the returned 64\-bit unsigned integer\. The  
&emsp;&emsp;conversion for component c of v to fixed point is done as follows :  
&emsp;&emsp;``` round(clamp(c, 0, +1) * 65535.0) ```\. The first component of the vector will be  
&emsp;&emsp;written to the least significant bits of the output; the last component will be written to  
&emsp;&emsp;the most significant bits\.  
  
### packUnorm4x4\(\) function  
#### <code>glm.<code>**packUnorm4x4**(**v**: *fvec4*) -\> *int*</code></code>  
&emsp;&emsp;Convert each component of the normalized floating\-point vector into unsigned integer  
&emsp;&emsp;values\.  
  
### unpackF2x11\_1x10\(\) function  
#### <code>glm.<code>**unpackF2x11_1x10**(**p**: *int*) -\> *vec3*</code></code>  
&emsp;&emsp;First, unpacks a single 32\-bit unsigned integer ``` p ``` into two 11\-bit signless floating\-point  
&emsp;&emsp;values and one 10\-bit signless floating\-point value\. Then, each component is converted to a  
&emsp;&emsp;normalized floating\-point value to generate the returned three\-component vector\. The  
&emsp;&emsp;first component of the returned vector will be extracted from the least significant bits of  
&emsp;&emsp;the input; the last component will be extracted from the most significant bits\.  
  
### unpackF3x9\_E1x5\(\) function  
#### <code>glm.<code>**unpackF3x9_E1x5**(**p**: *int*) -\> *vec3*</code></code>  
&emsp;&emsp;First, unpacks a single 32\-bit unsigned integer p into two 11\-bit signless floating\-point  
&emsp;&emsp;values and one 10\-bit signless floating\-point value\. Then, each component is converted to a  
&emsp;&emsp;normalized floating\-point value to generate the returned three\-component vector\. The  
&emsp;&emsp;first component of the returned vector will be extracted from the least significant bits of  
&emsp;&emsp;the input; the last component will be extracted from the most significant bits\.  
&emsp;&emsp;unpackF3x9\_E1x5 allows decoding RGBE / RGB9E5 data  
  
### unpackHalf\(\) function  
#### <code>glm.<code>**unpackHalf**(**p**: *u16vecN*) -\> *vecN*</code></code>  
&emsp;&emsp;Returns a floating\-point vector with components obtained by reinterpreting an integer  
&emsp;&emsp;vector as 16\-bit floating\-point numbers and converting them to 32\-bit floating\-point  
&emsp;&emsp;values\. The first component of the vector is obtained from the 16 least\-significant bits  
&emsp;&emsp;of ``` v ```; the forth component is obtained from the 16 most\-significant bits of ``` v ```\.  
  
### unpackHalf1x16\(\) function  
#### <code>glm.<code>**unpackHalf1x16**(**p**: *int*) -\> *float*</code></code>  
&emsp;&emsp;Returns a floating\-point scalar with components obtained by unpacking a 16\-bit unsigned  
&emsp;&emsp;integer into a 16\-bit value, interpreted as a 16\-bit floating\-point number according to the  
&emsp;&emsp;OpenGL Specification, and converting it to 32\-bit floating\-point values\.  
  
### unpackHalf4x16\(\) function  
#### <code>glm.<code>**unpackHalf4x16**(**p**: *int*) -\> *vec4*</code></code>  
&emsp;&emsp;Returns a four\-component floating\-point vector with components obtained by unpacking a  
&emsp;&emsp;64\-bit unsigned integer into four 16\-bit values, interpreting those values as 16\-bit  
&emsp;&emsp;floating\-point numbers according to the OpenGL Specification, and converting them to 32\-bit  
&emsp;&emsp;floating\-point values\. The first component of the vector is obtained from the 16  
&emsp;&emsp;least\-significant bits of ``` v ```; the forth component is obtained from the 16 most\-significant  
&emsp;&emsp;bits of ``` v ```\.  
  
### unpackI3x10\_1x2\(\) function  
#### <code>glm.<code>**unpackI3x10_1x2**(**p**: *int*) -\> *ivec4*</code></code>  
&emsp;&emsp;Unpacks a single 32\-bit unsigned integer p into three 10\-bit and one 2\-bit signed integers\.  
&emsp;&emsp;The first component of the returned vector will be extracted from the least significant  
&emsp;&emsp;bits of the input; the last component will be extracted from the most significant bits\.  
  
### unpackInt2x16\(\) function  
#### <code>glm.<code>**unpackInt2x16**(**p**: *int*) -\> *i16vec2*</code></code>  
&emsp;&emsp;Convert a packed integer into an integer vector\.  
  
### unpackInt2x32\(\) function  
#### <code>glm.<code>**unpackInt2x32**(**p**: *int*) -\> *i32vec2*</code></code>  
&emsp;&emsp;Convert a packed integer into an integer vector\.  
  
### unpackInt2x8\(\) function  
#### <code>glm.<code>**unpackInt2x8**(**p**: *int*) -\> *i8vec2*</code></code>  
&emsp;&emsp;Convert a packed integer into an integer vector\.  
  
### unpackInt4x16\(\) function  
#### <code>glm.<code>**unpackInt4x16**(**p**: *int*) -\> *i16vec4*</code></code>  
&emsp;&emsp;Convert a packed integer into an integer vector\.  
  
### unpackInt4x8\(\) function  
#### <code>glm.<code>**unpackInt4x8**(**p**: *int*) -\> *i8vec4*</code></code>  
&emsp;&emsp;Convert a packed integer into an integer vector\.  
  
### unpackRGBM\(\) function  
#### <code>glm.<code>**unpackRGBM**(**rgbm**: *vec4*) -\> *vec3*</code></code>  
&emsp;&emsp;Returns a floating\-point vector with components obtained by reinterpreting an integer  
&emsp;&emsp;vector as 16\-bit floating\-point numbers and converting them to 32\-bit floating\-point  
&emsp;&emsp;values\. The first component of the vector is obtained from the 16 least\-significant bits of  
&emsp;&emsp;``` v ```; the forth component is obtained from the 16 most\-significant bits of ``` v ```\.  
  
### unpackSnorm\(\) function  
#### <code>glm.<code>**unpackSnorm**(**t**: *type*, **v**: *vecN*) -\> *vecN*</code></code>  
&emsp;&emsp;Convert a packed integer to a normalized floating\-point vector of type ``` t ```\.  
&emsp;&emsp;``` t ``` can be either ``` glm.float ``` or ``` glm.double ```\.  
  
### unpackSnorm1x16\(\) function  
#### <code>glm.<code>**unpackSnorm1x16**(**p**: *int*) -\> *float*</code></code>  
&emsp;&emsp;First, unpacks a single 16\-bit unsigned integer ``` p ``` into a single 16\-bit signed integers\.  
&emsp;&emsp;Then, each component is converted to a normalized floating\-point value to generate the  
&emsp;&emsp;returned scalar\. The conversion for unpacked fixed\-point value ``` f ``` to floating point is  
&emsp;&emsp;done as follows : ``` clamp(f / 32767.0, -1, +1) ```  
  
### unpackSnorm1x8\(\) function  
#### <code>glm.<code>**unpackSnorm1x8**(**p**: *int*) -\> *float*</code></code>  
&emsp;&emsp;First, unpacks a single 8\-bit unsigned integer ``` p ``` into a single 8\-bit signed integers\.  
&emsp;&emsp;Then, the value is converted to a normalized floating\-point value to generate the  
&emsp;&emsp;returned scalar\. The conversion for unpacked fixed\-point value ``` f ``` to floating point is  
&emsp;&emsp;done as follows : ``` clamp(f / 127.0, -1, +1) ```  
  
### unpackSnorm2x8\(\) function  
#### <code>glm.<code>**unpackSnorm2x8**(**p**: *int*) -\> *vec2*</code></code>  
&emsp;&emsp;First, unpacks a single 16\-bit unsigned integer p into a pair of 8\-bit signed integers\.  
&emsp;&emsp;Then, each component is converted to a normalized floating\-point value to generate the  
&emsp;&emsp;returned two\-component vector\. The conversion for unpacked fixed\-point value ``` f ``` to  
&emsp;&emsp;floating point is done as follows : ``` clamp(f / 127.0, -1, +1) ```  
&emsp;&emsp;The first component of the returned vector will be extracted from the least significant  
&emsp;&emsp;bits of the input; the last component will be extracted from the most significant bits\.  
  
### unpackSnorm3x10\_1x2\(\) function  
#### <code>glm.<code>**unpackSnorm3x10_1x2**(**p**: *int*) -\> *vec4*</code></code>  
&emsp;&emsp;First, unpacks a single 32\-bit unsigned integer ``` p ``` into four 16\-bit signed integers\. Then,  
&emsp;&emsp;each component is converted to a normalized floating\-point value to generate the returned  
&emsp;&emsp;four\-component vector\. The conversion for unpacked fixed\-point value ``` f ``` to floating point  
&emsp;&emsp;is done as follows : ``` unpackSnorm3x10_1x2(xyz) ``` : ``` clamp(f / 511.0, -1, +1) ```  
&emsp;&emsp;``` unpackSnorm3x10_1x2(w) ``` : ``` clamp(f / 511.0, -1, +1) ```\. The first component of the returned  
&emsp;&emsp;vector will be extracted from the least significant bits of the input; the last component  
&emsp;&emsp;will be extracted from the most significant bits\.  
  
### unpackSnorm4x16\(\) function  
#### <code>glm.<code>**unpackSnorm4x16**(**p**: *int*) -\> *vec4*</code></code>  
&emsp;&emsp;First, unpacks a single 64\-bit unsigned integer ``` p ``` into four 16\-bit signed integers\. Then,  
&emsp;&emsp;each component is converted to a normalized floating\-point value to generate the returned  
&emsp;&emsp;four\-component vector\. The conversion for unpacked fixed\-point value ``` f ``` to floating point  
&emsp;&emsp;is done as follows : ``` clamp(f / 32767.0, -1, +1) ```  
&emsp;&emsp;The first component of the returned vector will be extracted from the least significant  
&emsp;&emsp;bits of the input; the last component will be extracted from the most significant bits\.  
  
### unpackU3x10\_1x2\(\) function  
#### <code>glm.<code>**unpackU3x10_1x2**(**p**: *int*) -\> *uvec4*</code></code>  
&emsp;&emsp;Unpacks a single 32\-bit unsigned integer ``` p ``` into three 10\-bit and one 2\-bit unsigned  
&emsp;&emsp;integers\. The first component of the returned vector will be extracted from the least  
&emsp;&emsp;significant bits of the input; the last component will be extracted from the most  
&emsp;&emsp;significant bits\.  
  
### unpackUint2x16\(\) function  
#### <code>glm.<code>**unpackUint2x16**(**p**: *int*) -\> *u16vec2*</code></code>  
&emsp;&emsp;Convert a packed integer into an integer vector\.  
  
### unpackUint2x32\(\) function  
#### <code>glm.<code>**unpackUint2x32**(**p**: *int*) -\> *u32vec2*</code></code>  
&emsp;&emsp;Convert a packed integer into an integer vector\.  
  
### unpackUint2x8\(\) function  
#### <code>glm.<code>**unpackUint2x8**(**p**: *int*) -\> *u8vec2*</code></code>  
&emsp;&emsp;Convert a packed integer into an integer vector\.  
  
### unpackUint4x16\(\) function  
#### <code>glm.<code>**unpackUint4x16**(**p**: *int*) -\> *u16vec4*</code></code>  
&emsp;&emsp;Convert a packed integer into an integer vector\.  
  
### unpackUint4x8\(\) function  
#### <code>glm.<code>**unpackUint4x8**(**p**: *int*) -\> *u8vec4*</code></code>  
&emsp;&emsp;Convert a packed integer into an integer vector\.  
  
### unpackUnorm\(\) function  
#### <code>glm.<code>**unpackUnorm**(**t**: *type*, **v**: *vecN*) -\> *vecN*</code></code>  
&emsp;&emsp;Convert a packed unsigned integer to a normalized floating\-point vector of type ``` t ```\.  
&emsp;&emsp;``` t ``` can be either ``` glm.float ``` or ``` glm.double ```\.  
  
### unpackUnorm1x16\(\) function  
#### <code>glm.<code>**unpackUnorm1x16**(**p**: *int*) -\> *float*</code></code>  
&emsp;&emsp;First, unpacks a single 16\-bit unsigned integer ``` p ``` into a of 16\-bit unsigned integers\.  
&emsp;&emsp;Then, the value is converted to a normalized floating\-point value to generate the  
&emsp;&emsp;returned scalar\. The conversion for unpacked fixed\-point value ``` f ``` to floating point is  
&emsp;&emsp;done as follows : ``` f / 65535.0 ```  
  
### unpackUnorm1x5\_1x6\_1x5\(\) function  
#### <code>glm.<code>**unpackUnorm1x5_1x6_1x5**(**p**: *int*) -\> *vec3*</code></code>  
&emsp;&emsp;Convert a packed integer to a normalized floating\-point vector\.  
  
### unpackUnorm1x8\(\) function  
#### <code>glm.<code>**unpackUnorm1x8**(**p**: *int*) -\> *float*</code></code>  
&emsp;&emsp;Convert a single 8\-bit integer to a normalized floating\-point value\. The conversion for  
&emsp;&emsp;unpacked fixed\-point value ``` f ``` to floating point is done as follows :  
&emsp;&emsp;``` f / 255.0 ```  
  
### unpackUnorm2x3\_1x2\(\) function  
#### <code>glm.<code>**unpackUnorm2x3_1x2**(**p**: *int*) -\> *vec3*</code></code>  
&emsp;&emsp;Convert a packed integer to a normalized floating\-point vector\.  
  
### unpackUnorm2x4\(\) function  
#### <code>glm.<code>**unpackUnorm2x4**(**p**: *int*) -\> *vec2*</code></code>  
&emsp;&emsp;Convert a packed integer to a normalized floating\-point vector\.  
  
### unpackUnorm2x8\(\) function  
#### <code>glm.<code>**unpackUnorm2x8**(**p**: *int*) -\> *vec2*</code></code>  
&emsp;&emsp;First, unpacks a single 16\-bit unsigned integer ``` p ``` into a pair of 8\-bit unsigned integers\.  
&emsp;&emsp;Then, each component is converted to a normalized floating\-point value to generate the  
&emsp;&emsp;returned two\-component vector\. The conversion for unpacked fixed\-point value ``` f ``` to  
&emsp;&emsp;floating point is done as follows : ``` f / 255.0 ```\. The first component of the  
&emsp;&emsp;returned vector will be extracted from the least significant bits of the input; the last  
&emsp;&emsp;component will be extracted from the most significant bits\.  
  
### unpackUnorm3x10\_1x2\(\) function  
#### <code>glm.<code>**unpackUnorm3x10_1x2**(**p**: *int*) -\> *vec4*</code></code>  
&emsp;&emsp;First, unpacks a single 32\-bit unsigned integer ``` p ``` into four 16\-bit signed integers\.  
&emsp;&emsp;Then, each component is converted to a normalized floating\-point value to generate the  
&emsp;&emsp;returned four\-component vector\. The conversion for unpacked fixed\-point value ``` f ``` to  
&emsp;&emsp;floating point is done as follows : ``` unpackSnorm3x10_1x2(xyz) ``` : ``` clamp(f / 1023.0, 0, +1) ```  
&emsp;&emsp;``` unpackSnorm3x10_1x2(w) ``` : ``` clamp(f / 3.0, 0, +1) ```\. The first component of the returned vector  
&emsp;&emsp;will be extracted from the least significant bits of the input; the last component will be  
&emsp;&emsp;extracted from the most significant bits\.  
  
### unpackUnorm3x5\_1x1\(\) function  
#### <code>glm.<code>**unpackUnorm3x5_1x1**(**p**: *int*) -\> *vec4*</code></code>  
&emsp;&emsp;Convert a packed integer to a normalized floating\-point vector\.  
  
### unpackUnorm4x16\(\) function  
#### <code>glm.<code>**unpackUnorm4x16**(**p**: *int*) -\> *vec4*</code></code>  
&emsp;&emsp;First, unpacks a single 64\-bit unsigned integer ``` p ``` into four 16\-bit unsigned integers\.  
&emsp;&emsp;Then, each component is converted to a normalized floating\-point value to generate the  
&emsp;&emsp;returned four\-component vector\. The conversion for unpacked fixed\-point value ``` f ``` to  
&emsp;&emsp;floating point is done as follows : ``` f / 65535.0 ```\. The first component of  
&emsp;&emsp;the returned vector will be extracted from the least significant bits of the input; the  
&emsp;&emsp;last component will be extracted from the most significant bits\.  
  
### unpackUnorm4x4\(\) function  
#### <code>glm.<code>**unpackUnorm4x4**(**p**: *int*) -\> *vec4*</code></code>  
&emsp;&emsp;Convert a packed integer to a normalized floating\-point vector\.  
  
