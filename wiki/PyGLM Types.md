[//]: # (generated using SlashBack 0.2.0)

**PyGLM** brings a couple of types with it\.  
  
These types represent either **vectors**, **matrices** or **quaternions** or an **array** containing the aforementioned\.  
  
  
1.  A **vector** usually is an array of **1 to 4 numbers** that serve as **positions** or **directions** in a   
1 to 4 dimensional coordinate system \(respectively\)\.  
They support a lot of operations necessary in **linear algebra**\.&nbsp;&nbsp;  
Vector types are expressed as **glm\.vecN** \(*N* being the length\)\.&nbsp;&nbsp;  
For example a **2D** vector would be expressed as ``` glm.vec2 ```\.  
Refer to [using vectors](https://github.com/Zuzu-Typ/PyGLM/wiki/Using-vectors) for a complete type reference\.  
  
2.  A **matrix** is a **2 dimensional array** of numbers ranging from **2x2** \(4 numbers\) to **4x4** \(16 numbers\)\.&nbsp;&nbsp;  
They aid in a lot of complex vector manipulations\.&nbsp;&nbsp;  
Matrix types are expressed as **glm\.matNxM** \(*N* being the columns and *M* being the rows\)\.  
So a **4x4** matrix would be ``` glm.mat4x4 ```, or ``` glm.mat4 ``` for short \(because *N* and *M* are equal\)\.  
Refer to [using matrices](https://github.com/Zuzu-Typ/PyGLM/wiki/Using-matrices) for a complete type reference\.  
Note: *Yes, columns and rows are not in the natural order \- this is a flaw of glm\.*  
  
3.  A **quaternion** is an **array of 4 numbers** that can be used for complex vector manipulations\.   
They are made up of a scalar part ``` (w) ``` and a vector part ``` (x, y, z) ``` and are sometimes displayed as   
``` (w + x*i + y*j + z*k) ```, where ``` i ```, ``` j ``` and ``` k ``` are imaginary numbers\.  
Quaternion types are simply expressed as ``` glm.quat ```\.  
Refer to [using quaternions](https://github.com/Zuzu-Typ/PyGLM/wiki/Using-quaternions) for a complete type reference\.  
  
4. A PyGLM **array** \(``` glm.array ```\) is a simple way of storing a copy of multiple instances of one of the aforementioned types\.  
This array can then be used to **transfer that data over to external C functions**, such as ``` glBufferData ``` from PyOpenGL\.  
Although PyGLM's arrays are a lot simpler than NumPy arrays, they're **quite a bit faster**\.  
Refer to [using arrays](https://github.com/Zuzu-Typ/PyGLM/wiki/Using-arrays) for a complete type reference\.  
  
  
**The following section is devoted to vectors, matrices and quaternions only\.**  
  
All of these types use **32\-bit floating point numbers** to store their values\.&nbsp;&nbsp;  
PyGLM does however provide **other data types**\.&nbsp;&nbsp;  
For **all of the aforementioned**:  

Data type		| Description						| Prefix
-|-|-
**double** 	| 64\-bit floating point number 	| ``` d ``` or ``` f64 ```
**float** 	| 32\-bit floating point number 	| ``` f ``` or ``` f32 ``` or none
  
  
Additionally for **matrices** and **vectors**:  

Data type		| Description						| Prefix
-|-|-
**int** 		| 32\-bit signed integer 			| ``` i ``` or ``` i32 ```
**uint** 		| 32\-bit unsigned integer 		| ``` u ``` or ``` u32 ```  
  
  
And additionally for **vectors**:  

Data type		| Description						| Prefix
-|-|-
**int64** 	| 64\-bit signed integer 			| ``` i64 ```
**int16** 	| 16\-bit signed integer 			| ``` i16 ```
**int8** 		| 8\-bit signed integer 			| ``` i8 ```
**uint64** 	| 64\-bit unsigned integer 		| ``` u64 ```
**uint16** 	| 16\-bit unsigned integer 		| ``` u16 ```
**uint8** 	| 8\-bit unsigned integer 			| ``` u8 ```
**bool** 		| boolean values 					| ``` b ```
  
  
If for example you want to use a **2D int64** vector, the type you want to use would be ``` glm.i64vec2 ```\.