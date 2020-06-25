[//]: # (generated using SlashBack 0.2.0)

PyGLM's array type was introduced in version 2\.0\.0 to reduce the likelihood of requiring users to also use numpy besides glm\.  
  
It's mainly intended to **provide a way of passing multiple glm type instances** \(such as vectors\) **to external C functions**   
\(such as glBufferData\)\.  
  
## Table of contents  
  
1. [About arrays](#about-arrays)  
2. [Initialization](#initialization)  
    * [\.\. with vectors, matrices or quaternions](#-with-vectors-matrices-or-quaternions)  
    * [\.\. with other array instances](#-with-other-array-instances)  
    * [\.\. with other compatible arrays / lists / iterables](#-with-other-compatible-arrays--lists--iterables)  
3. [Members](#members)  
4. [Methods](#methods)  
    * [The copy protocol](#the-copy-protocol)  
    * [To list / tuple](#to-list--tuple)  
5. [Operators](#operators)  
    * [concat](#concat--operator)  
    * [repeat](#repeat--operator)  
    * [getitem and setitem](#getitem-and-setitem--operator)  
    * [contains](#contains-in-operator)  
    * [len](#len)  
    * [str](#str)  
    * [repr](#repr)  
    * [iter](#iter)  
  
  
## About arrays  
PyGLM's arrays are pure data copies of **one or multiple instances** of a **single PyGLM type**\.  
For example, an array could copy the data of five different ``` vec3 ``` instances\.  
However, it cannot copy the data of instances, that don't have the same type, like two ``` vec2 ``` instances and one ``` dvec2 ``` instance\.  
  
Additionally, the data inside the array is only a **copy**, thus if the data inside the array is modified, it won't affect the instances it copied the data from\.  
  
## Initialization  
Arrays can be initialized in a few different ways\.  
### \.\.\. with vectors, matrices or quaternions  
An array can be initialized with any number of vectors, metrices or quaternions, as long as they're all of the same type\.  
``` Python
>>> array(vec3(1, 2, 3), vec3(4, 5, 6))
array(vec3(1, 2, 3), vec3(4, 5, 6))

>>> array(vec3(), ivec3())
TypeError: arrays have to be initialized with arguments of the same glm type
 ```  
  
*Note: The list representations of vecs, mats and quats such as ``` ((1, 2), (3, 4)) ``` \(an alias for ``` mat2(1, 2, 3, 4) ```\) cannot be used here\.*  
  
### \.\.\. with other array instances  
You can obtain a copy of an array by using the copy constructor\.  
``` Python
arr_copy = array(arr)
 ```  
  
### \.\.\. with other compatible arrays / lists / iterables  
You can convert any compatible type to a PyGLM array\.  
This includes lists, tuples, etc\. and types that support the buffer protocol \(such as numpy's arrays\):  
``` Python
>>> array((ivec1(), ivec1()))
array(ivec1(0), ivec1(0))

>>> array([dmat2()])
array(dmat2x2((1, 0), (0, 1)))

>>> array(numpy.array([[1,2,3]]))
array(ivec3(1, 2, 3))

>>> array([[1,2,3]])
TypeError: invalid argument type(s) for array()
 ```  
*Note: array buffers that store length 4 items are interpreted as vec4s rather than quats\.*  
  
  
## Members  
PyGLM arrays have the following members:  

Name | Type | Description
-|-|-
element\_type | type | Type class of the contained elements \(e\.g\. ``` glm.vec3 ```\)
length | int | Number of elements contained by a given array
address | int | The memory address where an array's data is stored
ptr | c\_void\_p | A ctypes pointer that points to the content of an array
nbytes | int | The total data size in bytes
typecode | str | A single character, describing the data type of the elements' values, according to [this list](https://docs.python.org/3/library/struct.html#format-characters)
dtype | str | A numpy\-like data type string
itemsize | int | The size of one array element in bytes
dt\_size | int | The size of each single component of the elements in bytes \(size of data type\)
  
  
## Methods  
### The copy protocol  
Arrays support the copy protocol \(see [here](https://docs.python.org/3/library/copy.html)\)\.&nbsp;&nbsp;  
You can use ``` copy.copy(<array>) ``` or ``` copy.deepcopy(<array>) ``` to get a copy of an array\.  
  
### To list / tuple  
Any array has a ``` to_list() ``` and a ``` to_tuple() ``` function, which return's the arrays's data represented as a list or tuple respectively\.  
  
## Operators  
### concat \(``` + ``` operator\)  
Arrays can be combined / concaternated using the ``` + ``` operator, as long as they have the same element type\.  
``` Python
>>> array(vec2(1, 2)) + array(vec2(3, 4))
array(vec2(1, 2), vec2(3, 4))

>>> array(vec4()) + array(vec1())
ValueError: the given arrays are incompatible
 ```  
  
### repeat \(``` * ``` operator\)  
Arrays can be repeated a given number of times using the ``` * ``` operator\.  
``` Python
>>> array(vec3(1, 2, 3)) * 3
array(vec3(1, 2, 3), vec3(1, 2, 3), vec3(1, 2, 3))
 ```  
  
### getitem, setitem and delitem \(``` [] ``` operator\)  
You can access the individual elements of an array using indices\.  
Likewise you can also modify it's data by overwriting it or delete it using ``` del ```  
``` Python
>>> arr = array(vec1(1), vec1(2), vec1(3))
>>> arr[0]
vec1( 1 )

>>> arr[1] = vec1(0)
>>> arr
array(vec1(1), vec1(0), vec1(3))

>>> del arr[2]
>>> arr
array(vec1(1), vec1(0))
 ```  
  
You can also use slices to get or modify sub\-arrays:  
``` Python
>>> arr = array(vec1(1), vec1(2), vec1(3), vec1(4))
>>> arr[:2]
array(vec1(1), vec1(2))

>>> arr[::2]
array(vec1(1), vec1(3))

>>> del arr[1:3]
>>> arr
array(vec1(1), vec1(4))

>>> arr[:] = array(vec1(8), vec1(9))
>>> arr
array(vec1(8), vec1(9))
 ```  
  
Slices have the following syntax: ``` start_index : stop_index : optional_step ```, meaning you start at ``` start ``` and go ``` step ``` steps until you've reached or passed ``` stop ``` \(exclusive\) or the greatest possible index\.  
  
  
### contains \(``` in ``` operator  
You can check wether or not an element is present in the array using the ``` in ``` operator\.  
``` Python
>>> arr = array(vec2(1, 2), vec2(3, 4))
>>> vec2() in arr
False

>>> vec2(3, 4) in arr
True

>>> vec2(2, 3) in arr
False
 ```  
  
### len  
You can acquire the length of an array using the built\-in ``` len() ``` function\.  
``` Python
>>> len(array(vec1(0), vec1(1)))
2

>>> len(array(vec2(0, 1), vec2(2, 3), vec2(4, 5)))
3
 ```  
  
### str  
You can get a string representation of an array using the built\-in ``` str() ``` function\.  
Example:  
``` Python
>>> print(str(array(vec2(1, 2), vec2(3, 4), vec2(5, 6))))
[
 [            1,            2 ],
 [            3,            4 ],
 [            5,            6 ],
]

>>> print(str(array(mat2(1, 2, 3, 4), mat2(5, 6, 7, 8))))
[
 [
  [            1,            2 ],
  [            3,            4 ],
 ],
 [
  [            5,            6 ],
  [            7,            8 ],
 ],
]
 ```  
  
### repr  
You can get a reproducable string representation of an array using the built\-in ``` str() ``` function\.  
Example:  
``` Python
>>> print(repr(array(vec2(1, 2), vec2(3, 4), vec2(5, 6))))
array(vec2(1, 2), vec2(3, 4), vec2(5, 6))

>>> print(repr(array(mat2(1, 2, 3, 4), mat2(5, 6, 7, 8))))
array(mat2x2((1, 2), (3, 4)), mat2x2((5, 6), (7, 8)))
 ```  
  
### iter  
You can get an iterator from an array using ``` iter() ```  
``` Python
>>> arr = array(vec2(1, 2), vec2(3, 4))
>>> it = iter(arr)
>>> next(it)
vec2( 1, 2 )

>>> next(it)
vec2( 3, 4 )
 ```  
