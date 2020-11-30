[//]: # (generated using SlashBack 0.2.0)

  
# func\_integer methods  
The following methods are all part of the **func\_integer methods**\.  
It contains GLSL functions on integer types\.  
## Table of contents  
  
* [**bitCount** function](#bitcount-function)  
* [**bitfieldExtract** function](#bitfieldextract-function)  
* [**bitfieldInsert** function](#bitfieldinsert-function)  
* [**bitfieldReverse** function](#bitfieldreverse-function)  
* [**findLSB** function](#findlsb-function)  
* [**findMSB** function](#findmsb-function)  
* [**imulExtended** function](#imulextended-function)  
* [**uaddCarry** function](#uaddcarry-function)  
* [**umulExtended** function](#umulextended-function)  
* [**usubBorrow** function](#usubborrow-function)  
  
### bitCount\(\) function  
#### <code>glm.<code>**bitCount**(**v**: *int*) -\> *int*</code></code>  
&emsp;&emsp;Returns the number of bits set to ``` 1 ``` in the binary representation of ``` value ```\.  
  
#### <code>glm.<code>**bitCount**(**v**: *ivecN*) -\> *ivecN*</code></code>  
&emsp;&emsp;For every component ``` c ``` of ``` v ```:  
&emsp;&emsp;Returns the number of bits set to ``` 1 ``` in the binary representation of ``` c ```\.  
  
### bitfieldExtract\(\) function  
#### <code>glm.<code>**bitfieldExtract**(**value**: *int*, **offset**: *int*, **bits**: *int*) -\> *int*</code></code>  
&emsp;&emsp;Extracts bits ``` [offset, offset + bits - 1] ``` from value, returning them in the least  
&emsp;&emsp;significant bits of the result\. For unsigned data types, the most significant bits of the  
&emsp;&emsp;result will be set to zero\. For signed data types, the most significant bits will be set to  
&emsp;&emsp;the value of bit ``` offset + base - 1 ```\. If ``` bits ``` is zero, the result will be zero\. The result  
&emsp;&emsp;will be undefined if ``` offset ``` or ``` bits ``` is negative, or if the sum of ``` offset ``` and ``` bits ``` is  
&emsp;&emsp;greater than the number of bits used to store the operand\.  
  
#### <code>glm.<code>**bitfieldExtract**(**value**: *vecN*, **offset**: *int*, **bits**: *int*) -\> *vecN*</code></code>  
&emsp;&emsp;Returns ``` bitfieldExtract(c, offset, bits) ``` for every component ``` c ``` of ``` value ```\.  
  
### bitfieldInsert\(\) function  
#### <code>glm.<code>**bitfieldInsert**(**base**: *int*, **insert**: *int*, **offset**: *int*, **bits**: *int*) -\> *int*</code></code>  
&emsp;&emsp;Returns the insertion the bits least\-significant bits of insert into base\. The result will  
&emsp;&emsp;have ``` bits[offset, offset + bits - 1] ``` taken from ``` bits[0, bits - 1] ``` of ``` insert ```, and all other  
&emsp;&emsp;bits taken directly from the corresponding bits of ``` base ```\. If ``` bits ``` is zero, the result will  
&emsp;&emsp;simply be ``` base ```\. The result will be undefined if ``` offset ``` or ``` bits ``` is negative, or if the sum of  
&emsp;&emsp;``` offset ``` and ``` bits ``` is greater than the number of bits used to store the operand\.  
  
#### <code>glm.<code>**bitfieldInsert**(**base**: *vecN*, **insert**: *vecN*, **offset**: *int*, **bits**: *int*) -\> *vecN*</code></code>  
&emsp;&emsp;Returns ``` bitfieldInsert(base[i], insert[i], offset, bits) ``` for every index ``` i ```\.  
  
### bitfieldReverse\(\) function  
#### <code>glm.<code>**bitfieldReverse**(**value**: *int*) -\> *int*</code></code>  
&emsp;&emsp;Returns the reversal of the bits of ``` value ```\. The bit numbered ``` n ``` of the result will be taken  
&emsp;&emsp;from ``` bit(bits - 1) - n ``` of ``` value ```, where ``` bits ``` is the total number of bits used to represent  
&emsp;&emsp;``` value ```\.  
  
#### <code>glm.<code>**bitfieldReverse**(**value**: *vecN*) -\> *vecN*</code></code>  
&emsp;&emsp;Returns the reversal of the bits of ``` value ```\. The bit numbered ``` n ``` of the result will be taken  
&emsp;&emsp;from ``` bit(bits - 1) - n ``` of ``` value ```, where ``` bits ``` is the total number of bits used to represent  
&emsp;&emsp;``` value ```\.  
  
### findLSB\(\) function  
#### <code>glm.<code>**findLSB**(**value**: *int*) -\> *int*</code></code>  
&emsp;&emsp;Returns the bit number of the least significant bit set to ``` 1 ``` in the binary representation  
&emsp;&emsp;of ``` value ```\. If ``` value ``` is zero, ``` -1 ``` will be returned\.  
  
#### <code>glm.<code>**findLSB**(**value**: *vecN*) -\> *vecN*</code></code>  
&emsp;&emsp;Returns the bit number of the least significant bit set to ``` 1 ``` in the binary representation  
&emsp;&emsp;of ``` value ```\. If ``` value ``` is zero, ``` -1 ``` will be returned\.  
  
### findMSB\(\) function  
#### <code>glm.<code>**findMSB**(**value**: *int*) -\> *int*</code></code>  
&emsp;&emsp;Returns the bit number of the most significant bit in the binary representation of ``` value ```\.  
&emsp;&emsp;For positive integers, the result will be the bit number of the most significant bit set to  
&emsp;&emsp;``` 1 ```\. For negative integers, the result will be the bit number of the most significant bit set  
&emsp;&emsp;to ``` 0 ```\. For a value of zero or negative one, ``` -1 ``` will be returned\.  
  
#### <code>glm.<code>**findMSB**(**value**: *vecN*) -\> *vecN*</code></code>  
&emsp;&emsp;Returns the bit number of the least significant bit set to ``` 1 ``` in the binary representation  
&emsp;&emsp;of ``` value ```\. If ``` value ``` is zero, ``` -1 ``` will be returned\.  
  
### imulExtended\(\) function  
#### <code>glm.<code>**imulExtended**(**x**: *ivecN*, **y**: *ivecN*, **msb**: *ivecN*, **lsb**: *ivecN*) -\> *ivecN*</code></code>  
&emsp;&emsp;Multiplies 32\-bit integers ``` x ``` and ``` y ```, producing a 64\-bit result\. The 32 least\-significant  
&emsp;&emsp;bits are returned in ``` lsb ```\. The 32 most\-significant bits are returned in ``` msb ```\.  
  
### uaddCarry\(\) function  
#### <code>glm.<code>**uaddCarry**(**x**: *uvecN*, **y**: *uvecN*, **carry**: *uvecN*) -\> *uvecN*</code></code>  
&emsp;&emsp;Adds 32\-bit unsigned integer ``` x ``` and ``` y ```, returning the ``` sum ``` modulo ``` pow(2, 32) ```\. The value carry  
&emsp;&emsp;is set to ``` 0 ``` if the ``` sum ``` was less than ``` pow(2, 32) ```, or to ``` 1 ``` otherwise\.  
  
### umulExtended\(\) function  
#### <code>glm.<code>**umulExtended**(**x**: *uvecN*, **y**: *uvecN*, **msb**: *uvecN*, **lsb**: *uvecN*) -\> *uvecN*</code></code>  
&emsp;&emsp;Multiplies 32\-bit integers ``` x ``` and ``` y ```, producing a 64\-bit result\. The 32 least\-significant  
&emsp;&emsp;bits are returned in ``` lsb ```\. The 32 most\-significant bits are returned in ``` msb ```\.  
  
### usubBorrow\(\) function  
#### <code>glm.<code>**usubBorrow**(**x**: *uvecN*, **y**: *uvecN*, **borrow**: *uvecN*) -\> *uvecN*</code></code>  
&emsp;&emsp;Subtracts the 32\-bit unsigned integer ``` y ``` from ``` x ```, returning the difference if non\-negative,  
&emsp;&emsp;or ``` pow(2, 32) ``` plus the difference otherwise\. The value borrow is set to ``` 0 ``` if ``` x >= y ```, or to  
&emsp;&emsp;``` 1 ``` otherwise\.  
  
