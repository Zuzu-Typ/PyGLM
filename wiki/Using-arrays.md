[//]: # (generated using SlashBack 0.2.0)

# Using Arrays  
PyGLM's array type was introduced in version 2\.0\.0 to reduce the likelihood of requiring users to also use numpy besides glm\.  
  
It's mainly intended to **provide a way of passing multiple glm type instances** \(such as vectors\) **to external C functions**   
\(such as glBufferData\)\.  
  
## Table of contents  
  
1. [About arrays](#about-arrays)  
2. [Initialization](#initialization)  
    * [\.\. with vectors, matrices, quaternions or ctypes number objects](#-with-vectors-matrices-quaternions-or-ctypes-number-objects)  
    * [\.\. with other array instances](#-with-other-array-instances)  
    * [\.\. with other compatible arrays / lists / iterables](#-with-other-compatible-arrays--lists--iterables)  
    * [\.\. as a reference instead of a copy](#-as-a-reference-instead-of-a-copy)  
    * [\.\. with zeros](#-with-zeros)  
    * [\.\. from numbers](#-from-numbers)  
3. [Members](#members)  
4. [Methods](#methods)  
    * [The copy protocol](#the-copy-protocol)  
    *  [Pickling](#pickling)  
    * [To list / tuple](#to-list--tuple)  
    * [To and from bytes](#to-and-from-bytes)  
    * [From Numbers](#from-numbers)  
    * [As Reference](#as-reference)  
    * [Zeros](#zeros)  
    * [Filter](#filter)  
    * [Map](#map)  
    * [Sort](#sort)  
    * [Split components](#split-components)  
    * [Reduce](#reduce)  
    * [Concat](#concat)  
    * [Repeat](#repeat)  
5. [Operators](#operators)  
    * [Numeric operations](#numeric-operations)  
    * [getitem and setitem](#getitem-and-setitem--operator)  
    * [contains](#contains-in-operator)  
    * [len](#len)  
    * [str](#str)  
    * [repr](#repr)  
    * [iter](#iter)  
    * [hash](#hash)  
  
  
## About arrays  
PyGLM's arrays are pure data copies of **one or multiple instances** of a **single PyGLM type**\.  
For example, an array could copy the data of five different ``` vec3 ``` instances\.  
However, it cannot copy the data of instances, that don't have the same type, like two ``` vec2 ``` instances and one ``` dvec2 ``` instance\.  
  
Additionally, the data inside the array is only a **copy**, thus if the data inside the array is modified, it won't affect the instances it copied the data from\.  
  
## Initialization  
Arrays can be initialized in a few different ways\.  
### \.\.\. with vectors, matrices, quaternions or ctypes number objects  
An array can be initialized with any number of vectors, metrices or quaternions, as long as they're all of the same type\.  
``` Python
>>> array(vec3(1, 2, 3), vec3(4, 5, 6))
array(vec3(1, 2, 3), vec3(4, 5, 6))

>>> array(vec3(), ivec3())
TypeError: arrays have to be initialized with arguments of the same glm type
 ```  
The same holds true for ctypes numbers:  
``` Python
>>> array(int8(2), int8(3))
array(c_int8(2), c_int8(3))

>>> array(int8(2), int16(3))
TypeError: arrays have to be initialized with arguments of the same type
 ```  
You can also create an array of ctypes numbers from normal numbers using ``` from_numbers ```, which needs to have the data type as it's first argument:  
``` Python
>>> array.from_numbers(int8, 2, 3)
array(c_int8(2), c_int8(3))

>>> array(int8, 2, 3) # alternative way
array(c_int8(2), c_int8(3))
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
  
### \.\.\. as a reference instead of a copy  
If you don't need or don't want a copy of an array or buffer, but want a reference instead \(i\.e\. use the same data in memory as another array / buffer\), you can do so by using ``` glm.array.as_reference ```\.  
``` Python
>>> arr = array(vec3(1))
>>> arr2 = array.as_reference(arr)
>>> arr == arr2
True

>>> arr.address == arr2.address
True

>>> arr[0] = vec3(2) # if you change one of them, the other changes as well
>>> arr2
array(vec3(2, 2, 2))
 ```  
  
*Note: ``` as_reference ``` only works with array instances or buffers \(e\.g\. ``` numpy.array ```\)\.  
Also it may not always be possible to create a reference copy, in which case a normal copy is made and a warning is raised\.*  
  
### \.\.\. with zeros  
You can initialize an array with any given number of zeros or a given type:  
``` Python
>>> array.zeros(4, uint8)
array(c_uint8(0), c_uint8(0), c_uint8(0), c_uint8(0))

>>> array.zeros(2, vec3)
array(vec3(0, 0, 0), vec3(0, 0, 0))

 ```  
  
### \.\.\. from numbers  
You can initialize an array with numbers and a \(ctypes\) data type using ``` glm.array.from_numbers ```:  
``` Python
>>> array.from_numbers(int8, 1, 2, 3)
array(c_int8(1), c_int8(2), c_int8(3))

>>> array.from_numbers(float32, 4.2, 1.1)
array(c_float(4.2), c_float(1.1))

>>> array(int8, 1, 2, 3) # You can also use the array() constructor, but beware that the dedicated function is faster
array(c_int8(1), c_int8(2), c_int8(3))

>>> array.from_numbers(vec1, 1, 2, 3)
TypeError: Invalid argument type for from_number(), expected a ctypes data type as the first argument. Got 'type'
 ```  
  
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
ctype | str | The respective ctypes data type
itemsize | int | The size of one array element in bytes
dt\_size | int | The size of each single component of the elements in bytes \(size of data type\)
readonly | int | Whether or not the array is read\-only
reference | int | The reference to the array owning the data \(if any\)
  
  
## Methods  
### The copy protocol  
Arrays support the copy protocol \(see [here](https://docs.python.org/3/library/copy.html)\)\.&nbsp;&nbsp;  
You can use ``` copy.copy(<array>) ``` or ``` copy.deepcopy(<array>) ``` to get a copy of an array\.  
  
### Pickling  
Arrays support [pickling](https://docs.python.org/3/library/pickle.html#module-interface) \(as of PyGLM 2\.0\.0\), which is Python's serialization method\.  
  
### To list / tuple  
Any array has a ``` to_list() ``` and a ``` to_tuple() ``` function, which return's the arrays's data represented as a list or tuple respectively\.  
  
### To and from bytes  
Any array has a ``` to_bytes() ``` and a static ``` from_bytes() ``` method, which allows for conversion of the array's data to and from bytes strings\.  
  
The ``` from_bytes() ``` method takes the bytes string and a target type \(``` uint8 ``` by default\) as arguments\.  
  
Example:  
``` Python
>>> array(uint8(1), uint8(2)).to_bytes()
b'\x01\x02'

>>> array.from_bytes(b"\x01\x02\x03", uint8)
array(c_uint8(1), c_uint8(2), c_uint8(3))

>>> array.from_bytes(b"\x00\x00\x00\x00", vec1)
array(vec1(0))

>>> array.from_bytes(b"\x00\x00\x00\x00" * 8, vec1)
array(vec1(0), vec1(0), vec1(0), vec1(0), vec1(0), vec1(0), vec1(0), vec1(0))
 ```  
  
### From Numbers  
The array class has a static ``` from_numbers ``` method, which allows for creation of a one\-dimensional array of numbers\.  
It takes a ctypes number type as it's first argument\.  
Example:  
``` Python
>>> array.from_numbers(c_float, 1.2, 3.4)
array(c_float(1.2), c_float(3.4))

>>> array.from_numbers(int32, 1, 3, 4, 5)
array(c_int32(1), c_int32(3), c_int32(4), c_int32(5))
 ```  
  
### As Reference  
The array class also has a static ``` as_reference ``` method, which allows for creation of a reference copy of other arrays or objects that support the buffer protocol\.  
  
A reference copy means that the newly created array will use the same data in memory as the source array\.  
It will also keep a reference to the object it shares the data with in the ``` reference ``` member\.  
Example:  
``` Python
>>> arr = array(vec2(1))
>>> arr2 = array.as_reference(arr)
>>> arr == arr2
True

>>> arr is arr2.reference
True

>>> arr[0] = vec2(-1) # if you change one of them, the other changes as well
>>> arr2
array(vec2(-1, -1))
 ```  
  
### Zeros  
Additionally, the array class has a static ``` zeros ``` method, which allows for creation of an array with items that are initialized with zeros\.  
This is the fastest way of creating an array, as it uses the builtin ``` calloc ``` function to allocate the memory and initialize it in the same step\.  
  
Example:  
``` Python
>>> array.zeros(4, uint8)
array(c_uint8(0), c_uint8(0), c_uint8(0), c_uint8(0))

>>> array.zeros(2, vec3)
array(vec3(0, 0, 0), vec3(0, 0, 0))

>>> array.zeros(1, mat4)
array(mat4x4((0, 0, 0, 0), (0, 0, 0, 0), (0, 0, 0, 0), (0, 0, 0, 0)))
 ```  
  
### Filter  
You can filter an array using a custom filtering function \(i\.e\. create a new array with all of this array's elements that match a certain criteria\)\.  
  
The filtering function is called with each element of the array and must return ``` True ``` for the elements to keep and ``` False ``` for the elements to discard\.  
  
Example:  
``` Python
>>> array(c_float, 1, 2, 3, 4, 5).filter(lambda x: x > 3)
array(c_float(4), c_float(5))

>>> array(vec3(1), vec3(2), vec3(3)).filter(lambda x: x.x + x.y == 2)
array(vec3(1, 1, 1))
 ```  
  
### Map  
You can map the elements of an array to one or any number of new values using a custom mapping function\.  
  
The mapping function is supplied with the amounts of arguments that the map function is given\.  
  
If the mapping function returns ``` None ```, the element is discarded \(much like filter\)\.  
If it returns a single value, that value becomes a new element of the resulting array\.  
If it returns a tuple, all of the tuple's items are added to the resulting array\.  
  
When the mapping function returns numbers, they are interpreted as ctypes numbers of the same type as the array that ``` map ``` was called on\.  
If you want to specify a custom ctypes type to use, there is a keyword argument called ``` ctype ``` that can be used to do that\.  
  
Example:  
``` Python
>>> array(c_float, 1, 2, 3).map(lambda x: x + 1)
array(c_float(2), c_float(3), c_float(4))

>>> array(c_float, 1, 2, 3).map(vec3)
array(vec3(1, 1, 1), vec3(2, 2, 2), vec3(3, 3, 3))

>>> array(c_float, 1, 2, 3, 4, 5).map(lambda x: x if x > 3 else None)
array(c_float(4), c_float(5))

>>> array(c_float, 1, 2).map(lambda x: (x, x))
array(c_float(1), c_float(1), c_float(2), c_float(2))

>>> array(c_float, 1, 2).map(lambda x: (3, 4) if x == 1 else 5)
array(c_float(3), c_float(4), c_float(5))

>>> arr1 = array(c_float, 1, 2, 3)
>>> arr2 = array(c_float, 4, 5, 6)
>>> arr1.map(lambda x, y: (x + x) * y, arr2)
array(c_float(8), c_float(20), c_float(36))

>>> arr3 = array(c_float, 7, 8, 9)
>>> arr1.map(lambda x, y, z: vec3(x, y, z), arr2, arr3)
array(vec3(1, 4, 7), vec3(2, 5, 8), vec3(3, 6, 9))

>>> arr1.map(lambda x, y, z: x * y + z, arr2, arr3)
array(c_float(11), c_float(18), c_float(27))

>>> arr4 = array(vec3(1, 2, 3), vec3( 4, 5, 6))
>>> arr4.map(normalize)
array(vec3(0.267261, 0.534522, 0.801784), vec3(0.455842, 0.569803, 0.683764))

>>> arr5 = array(vec3(7, 8, 9), vec3(10,11,12))
>>> arr4.map(dot, arr5)
array(c_float(50), c_float(167))

>>> arr4.map(dot, arr5, ctype = c_int32)
array(c_int32(50), c_int32(167))
 ```  
  
### Sort  
You can sort an array by using a custom sorting function\.  
  
The sorting function is called with two elements from the array and should return ``` -1 ``` if the first element comes before the second element in order\.  
Otherwise it should return ``` 0 ``` for equal elements and ``` 1 ``` if the first element comes after the second\.  
  
The sorting algorithm used is a recursive quicksort\.  
  
Example:  
``` Python
>>> arr = array(c_float, 6, 5, 4, 3, 2, 1)
>>> arr.sort(lambda x, y: -1 if x < y else 0 if x == y else 1)
>>> arr
array(c_float(1), c_float(2), c_float(3), c_float(4), c_float(5), c_float(6))

>>> arr.sort(lambda x, y: int(sign(y - x)))
>>> arr
array(c_float(6), c_float(5), c_float(4), c_float(3), c_float(2), c_float(1))

>>> arr.sort(cmp) # using glm.cmp
>>> arr
array(c_float(1), c_float(2), c_float(3), c_float(4), c_float(5), c_float(6))
 ```  
  
### Split components  
You can split an array into the components of it's elements using the ``` split_components() ``` method\.  
  
Splits each element of this array into it's components\.  
Returns one or multiple arrays wrapped in a tuple\.  
  
Example:  
``` Python
>>> arr = array(vec3(1, 2, 3), vec3(4, 5, 6))
>>> arr.split_components()
(array(c_float(1), c_float(4)), 
 array(c_float(2), c_float(5)), 
 array(c_float(3), c_float(6)))
 
>>> arr = array(mat2((1,2),(3,4)), mat2((5,6),(7,8)), mat2((9,10),(11,12)))
>>> arr.split_components()
(array(vec2(1, 2), vec2(5, 6), vec2(9, 10)), 
 array(vec2(3, 4), vec2(7, 8), vec2(11, 12)))
 
>>> arr = array(c_float, 6, 5, 4, 3, 2, 1) # doesn't have any components
>>> arr.split_components()
NotImplementedError: split_components() is not defined for ctypes arrays
 ```  
  
### Reduce  
Used to apply a binary function to this array's elements cumulatively, reducing the array to a single value\. If an optional initializer is given, it is placed before the first element\.  
  
Example:  
``` Python
>>> arr = array(c_float, 6, 5, 4, 3, 2, 1)
>>> arr.reduce(lambda x, y: x + y) # (((((6+5)+4)+3)+2)+1)
21.0

>>> arr.reduce(mul) # (((((6*5)*4)*3)*2)*1)
720.0

>>> arr.reduce(sub) # (((((6-5)-4)-3)-2)-1)
-9.0

>>> arr.reduce(sub, 21) # with initializer: ((((((21-6)-5)-4)-3)-2)-1)
0.0
 ```  
  
### Concat  
Arrays can be combined / concatenated using the ``` concat() ``` method, as long as they have the same element type\.  
``` Python
>>> array(vec2(1, 2)).concat(array(vec2(3, 4)))
array(vec2(1, 2), vec2(3, 4))

>>> array(vec4()).concat(array(vec1()))
ValueError: the given arrays are incompatible
 ```  
  
### Repeat  
Arrays can be repeated a given number of times using the ``` repeat() ``` method\.  
``` Python
>>> array(vec3(1, 2, 3)).repeat(3)
array(vec3(1, 2, 3), vec3(1, 2, 3), vec3(1, 2, 3))
 ```  
  
### Reinterpret cast  
You can reinterpret the data of an array as a different element type using the ``` reinterpret_cast() ``` method\.  
  
Example:  
``` Python
>>> array(vec3(1, 2, 3)).reinterpret_cast(float32)
array(c_float(1), c_float(2), c_float(3))

>>> array.from_numbers(float32, 1, 2, 3, 4, 5, 6, 7, 8, 9).reinterpret_cast(vec3)
array(vec3(1, 2, 3), vec3(4, 5, 6), vec3(7, 8, 9))
 ```  
  
## Operators  
### Numeric operations  
Arrays support a dozen numeric operations:  
  
*  Addition \(``` + ```\)  
*  Subtraction \(``` - ```\)  
*  Multiplication \(``` * ```\)  
*  Division \(``` / ```\)  
*  Modulus \(``` % ```\)  
*  Power \(``` ** ```\)  
*  Negation \(``` - ```\)  
*  Absolution \(``` abs() ```\)  
*  Inversion \(``` ~ ```\)  
*  Left shift \(``` << ```\)  
*  Right shift \(``` >> ```\)  
*  Bitwise and \(``` & ```\)  
*  Bitwise or \(``` | ```\)  
*  Bitwise xor \(``` ^ ```\)  
  
  
*Note: Not all types are compatible though\.*  
  
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
  
  
### contains \(``` in ``` operator\)  
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
  
### hash  
You can generate a hash value for arrays using ``` hash() ```  
Example:  
``` Python
>>> arr = array(vec3(1), vec3(2), vec3(3), vec3(4))
>>> hash(arr)
-2624592468369027458
>>> arr2 = array(vec3(1), vec3(2), vec3(3))
>>> hash(arr2)
9163283608357050393
>>> arr3 = arr2 + array(vec3(4))
>>> hash(arr3)
-2624592468369027458
 ```