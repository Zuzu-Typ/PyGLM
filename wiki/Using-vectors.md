[//]: # (generated using SlashBack 0.2.0)

# Using Vectors  
  
1.  [Initialization](#Initialization)  
    *  [with no arguments](#initialization-with-no-arguments)  
    *  [with single number](#Initialization-with-a-single-number)  
    *  [all components with numbers](#Initializing-all-components-with-numbers)  
    *  [copying a vector](#Copying-a-vector)  
    *  [with larger vectors](#Initializing-vectors-with-larger-vectors)  
    *  [with vectors and numbers](#Constructing-vectors-from-other-vectors-and-numbers)  
    *  [Lists \(and other iterables\)](#lists-and-other-iterables)  
    *  [Buffer protocol \(numpy, bytes\)](#objects-that-support-the-buffer-protocol-numpy-bytes)  
2.  [Members](#Members)  
3.  [Methods](#Methods)  
    *  [The copy protocol](#the-copy-protocol)  
    *  [Pickling](#pickling)  
    *  [To list / tuple](#to-list--tuple)  
    *  [To and from bytes](#to-and-from-bytes)  
4.  [Operators](#Operators)  
    *  [add](#add--operator)  
    *  [sub](#sub--operator)  
    *  [mul](#mul--operator)  
    *  [matmul](#matmul--operator)  
    *  [div](#div--operator)  
    *  [mod](#mod--operator)  
    *  [floordiv](#floordiv--operator)  
    *  [divmod](#divmod)  
    *  [lshift](#lshift--operator)  
    *  [rshift](#rshift--operator)  
    *  [and](#and--operator)  
    *  [or](#or--operator)  
    *  [xor](#xor--operator)  
    *  [pow](#pow--operator)  
    *  [len](#len)  
    *  [getitem and setitem](#getitem-and-setitem--operator)  
    *  [contains](#contains-in-operator)  
    *  [richcompare](#richcompare-eg--operator)  
    *  [iter](#iter)  
    *  [hash](#hash)  
  
## Initialization  
There are dozens of ways of constructing a vector\.&nbsp;&nbsp;  
For simplicity, if the same initialization process applies to all vector types, it will only be shown for ``` glm.vec2 ```\.  
#### Initialization with no arguments  
Initializing a vector without any additional arguments will set all of it's components to zero \(of the respective type\)\.&nbsp;&nbsp;  
i\.e\. ``` glm.vec2() ``` returns vector ``` (0.0, 0.0) ```\.&nbsp;&nbsp;  
A boolean vector would also be initialized with zero \(or ``` False ``` if you will\)\.  
#### Initialization with a single number  
Initializing a vector with a number will set all of it's components to the given number \(which may be converted if necessary\)\.&nbsp;&nbsp;  
i\.e\. ``` glm.vec2(2.43) ``` returns vector ``` (2.43, 2.43) ```\.&nbsp;&nbsp;  
#### Initializing all components with numbers  
A vector ``` vecN ``` can be initialized with *N* numbers, which will be copied \(or may be converted\) to their components\.&nbsp;&nbsp;  
i\.e\. ``` glm.vec2(1, 2) ``` returns vector ``` (1.0, 2.0) ```&nbsp;&nbsp;  
``` glm.vec3(4, 5, 6) ``` returns vector ``` (4.0, 5.0, 6.0) ```&nbsp;&nbsp;  
``` glm.ivec4(9, 8, 7, 6) ``` returns vector ``` (9, 8, 7, 6) ```  
#### Copying a vector  
A copy of a vector can be obtained by initializing a vector with an instance of a vector\.&nbsp;&nbsp;  
i\.e\. ``` glm.vec2(glm.vec2(3, 2)) ``` returns vector ``` (3.0, 2.0) ```&nbsp;&nbsp;  
This is what's known as the copy constructor\.  
#### Initializing vectors with larger vectors  
You can initialize any vector with a larger vector \(which will discard any values that don't fit into the new vector\)\.&nbsp;&nbsp;  
i\.e\. ``` glm.vec1(glm.vec3(1, 2, 3)) ``` returns vector ``` (1.0) ```&nbsp;&nbsp;  
likewise ``` glm.vec2(glm.vec4(5, 6, 7, 8)) ``` returns vector ``` (5.0, 6.0) ```  
#### Constructing vectors from other vectors and numbers  
As long as you don't use any ``` vec1 ```s in your equation, you can construct any vector from a combination of vectors and / or numbers if their sum equals the length of the target vector\.&nbsp;&nbsp;  
i\.e\. ``` glm.vec4(glm.vec2(1, 2), 3, 4) ``` returns vector ``` (1.0, 2.0, 3.0, 4.0) ```&nbsp;&nbsp;  
likewise ``` glm.vec3(5, glm.vec2(4, 3)) ``` returns vector ``` (5.0, 4.0, 3.0) ```&nbsp;&nbsp;  
  
but ``` glm.vec2(glm.vec1(1), 2) ``` doesn't work\.&nbsp;&nbsp;  
``` glm.vec3(glm.vec2(1, 2), glm.vec2(3, 4)) ``` also doesn't work\.  
### Lists \(and other iterables\)  
Instead of using vectors to initialize vectors, you can also use lists and other iterables\.&nbsp;&nbsp;  
e\.g\. ``` glm.vec2([1, 2]) ``` returns vector ``` (1.0, 2.0) ```&nbsp;&nbsp;  
or ``` glm.vec3((3, 4), 5) ``` returns vector ``` (3.0, 4.0, 5.0) ```&nbsp;&nbsp;  
  
### Objects that support the buffer protocol \(numpy, bytes\)  
A few objects in Python support a functionality called the buffer protocol\.&nbsp;&nbsp;  
One such example would be the Python ``` bytes ``` type or ``` numpy.array ```\.&nbsp;&nbsp;  
PyGLM also supports this protocol and thus can be converted to or from any other object that supports it, granted it's in a fitting format\.&nbsp;&nbsp;  
e\.g\. ``` bytes(glm.u8vec2(1,2)) ``` returns ``` b'\x01\x02' ```&nbsp;&nbsp;  
and ``` glm.u8vec2(b'\x01\x02') ``` returns an 8\-bit unsigned integer vector ``` (1, 2) ```  
  
or ``` glm.vec3(numpy.array([4,5,6])) ``` returns vector ``` (4.0, 5.0, 6.0) ```&nbsp;&nbsp;  
and ``` numpy.array(glm.vec3(4, 5, 6)) ``` returns ``` array([4., 5., 6.], dtype=float32) ```&nbsp;&nbsp;  
  
*Note: objects that use the buffer protocol *may* request a reference instead of a copy of the object, meaning that if you change the 'copy', you'll also change the original\.*  
  
## Members  
A vector has a member for each of it's values\.&nbsp;&nbsp;  
``` vec1 ``` has members: ``` (x) ```&nbsp;&nbsp;  
``` vec2 ``` has members: ``` (x, y) ```&nbsp;&nbsp;  
``` vec3 ``` has members: ``` (x, y, z) ```&nbsp;&nbsp;  
``` vec4 ``` has members: ``` (x, y, z, w) ```&nbsp;&nbsp;  
  
Using swizzling, you can also construct vectors from up to four members:  
``` Python
v  = vec4(1, 2, 3, 4)
v2 = v.xy             # returns vec2(1, 2)
v3 = v.zw             # returns vec2(3, 4)
v4 = v.xxxw           # returns vec4(1, 1, 1, 4)
 ```  
  
## Methods  
Any vector type implements the following methods:  
  
### The copy protocol  
Vectors support the copy protocol \(see [here](https://docs.python.org/3/library/copy.html)\)\.&nbsp;&nbsp;  
You can use ``` copy.copy(<vector>) ``` or ``` copy.deepcopy(<vector>) ``` to get a copy of a vector\.  
  
### Pickling  
Vectors support [pickling](https://docs.python.org/3/library/pickle.html#module-interface) \(as of PyGLM 2\.0\.0\), which is Python's serialization method\.  
  
### To list / tuple  
Any vector type has a ``` to_list() ``` and a ``` to_tuple() ``` function, which return's the vector's data represented as a list or tuple respectively\.  
  
### To and from bytes  
All vectors have a ``` to_bytes() ``` and a ``` from_bytes() ``` method, which allows for conversion of the vector's data to and from bytes strings\.  
  
## Operators  
Vector types support a *lot* of operators\.  
### add \(``` + ``` operator\)  
Vectors support addition with other vectors and numbers\.&nbsp;&nbsp;  
``` Python
sum1 = vec2(1, 2) + vec2(4, 0) # returns vec2(5, 2)
sum2 = vec2(1, 2) + 4          # returns vec2(5, 6)
 ```  
### sub \(``` - ``` operator\)  
Vectors support subtraction with other vectors and numbers\.&nbsp;&nbsp;  
``` Python
diff1 = vec2(1, 2) - vec2(4, 0) # returns vec2(-3,  2)
diff2 = vec2(1, 2) - 4          # returns vec2(-3, -2)
 ```  
### mul \(``` * ``` operator\)  
Vectors support multiplication with other vectors and numbers\.&nbsp;&nbsp;  
``` Python
prod1 = vec2(1, 2) * vec2(4, 0) # returns vec2(4, 0)
prod2 = vec2(1, 2) * 4          # returns vec2(4, 8)
 ```  
### matmul \(``` @ ``` operator\)  
Has the same effects as the ``` * ``` operator, but with the arguments switched\.  
I\.e\. ``` a * b == b @ a ```  
### div \(``` / ``` operator\)  
Vectors support division with other vectors and numbers\.&nbsp;&nbsp;  
``` Python
quot1 = vec2(1, 2) / vec2(4, 0.5) # returns vec2(0.25, 4  )
quot2 = vec2(1, 2) / 4            # returns vec2(0.25, 0.5)
 ```  
### mod \(``` % ``` operator\)  
Vectors support modulo operations with other vectors and numbers\.&nbsp;&nbsp;  
``` Python
mod1 = vec2(1, 2) % vec2(4, 2) # returns vec2(1, 0)
mod2 = vec2(1, 2) % 4            # returns vec2(1, 2)
 ```  
### floordiv \(``` // ``` operator\)  
Vectors support floored division with other vectors and numbers\.&nbsp;&nbsp;  
``` Python
fquot1 = vec2(1, 2) // vec2(4, 0.5) # returns vec2(0, 4)
fquot2 = vec2(1, 2) // 4            # returns vec2(0, 0)
 ```  
### divmod  
Vectors support combined floor division and modulo operations with other vectors and numbers\.&nbsp;&nbsp;  
``` Python
divmod1 = divmod(vec2(1, 2), vec2(4, 2)) # returns (vec2(0, 1), vec2(1, 0))
divmod2 = divmod(vec2(1, 2), 4)          # returns (vec2(0, 0), vec2(1, 2))
 ```  
### lshift \(``` << ``` operator\)  
Integer vectors support the bitwise left shift operator\.&nbsp;&nbsp;  
``` Python
>>> ivec3(1, 2, 3) << 4
ivec3( 16, 32, 48 )
>>> uvec3(1, 2, 3) << uvec3(1, 2, 3)
uvec3( 2, 8, 24 )
 ```  
### rshift \(``` >> ``` operator\)  
Integer vectors support the bitwise right shift operator\.&nbsp;&nbsp;  
``` Python
>>> ivec3(16, 32, 48) >> 4
ivec3( 1, 2, 3 )
>>> uvec3(2, 8, 24) >> uvec3(1, 2, 3)
uvec3( 1, 2, 3 )
 ```  
### and \(``` & ``` operator\)  
Integer vectors support the bitwise and operator\.&nbsp;&nbsp;  
``` Python
>>> ivec3(1, 2, 3) & 2
ivec3( 0, 2, 2 )
>>> uvec3(1, 2, 3) & uvec3(3, 2, 1)
uvec3( 1, 2, 1 )
 ```  
### or \(``` | ``` operator\)  
Integer vectors support the bitwise or operator\.&nbsp;&nbsp;  
``` Python
>>> ivec3(1, 2, 3) | 2
ivec3( 3, 2, 3 )
>>> uvec3(1, 2, 3) | uvec3(6, 5, 4)
uvec3( 7, 7, 7 )
 ```  
### xor \(``` ^ ``` operator\)  
Integer vectors support the bitwise xor operator\.&nbsp;&nbsp;  
``` Python
>>> ivec3(1, 2, 3) ^ 2
ivec3( 3, 0, 1 )
>>> uvec3(1, 2, 3) ^ uvec3(3, 2, 1)
uvec3( 2, 0, 2 )
 ```  
### pow \(``` ** ``` operator\)  
Vectors support pow operations with other vectors and numbers\.&nbsp;&nbsp;  
``` Python
pow1 = vec2(1, 2) ** vec2(4, 2) # returns vec2(1,  4)
pow2 = vec2(1, 2) ** 4          # returns vec2(1, 16)
 ```  
### len  
The length of a vector can be queried using ``` len() ```\.  
``` Python
vec_length = len(vec2()) # returns 2
 ```  
### getitem and setitem \(``` [] ``` operator\)  
You can get the values of a vector using indices\.  
``` Python
v = vec2(1, 2)
print(v[0]) # prints 1.0
print(v[1]) # prints 2.0
 ```  
Likewise you can set the values\.  
``` Python
v    = vec2(1, 2)
v[0] = 9
print(v.x) # prints 9.0
 ```  
### contains \(``` in ``` operator\)  
You can query wether or not a value is contained by a vector using the ``` in ``` operator\.  
``` Python
v     = vec2(1, 2)
true  = 2    in v
false = 2.01 in v
 ```  
### richcompare \(e\.g\. ``` == ``` operator\)  
You can compare vectors using the richcompare operators:  
``` Python
vec2(1, 2) == vec2(1, 2)    # True
vec2(1, 2) == vec2(2, 2)    # False
vec2(1, 2) == vec3(1, 2, 3) # False

vec2(1, 2) != vec2(1, 2)    # False
vec2(1, 2) != vec2(2, 2)    # True
vec2(1, 2) != vec3(1, 2, 3) # True

vec2(1, 2) < vec2(5, 5)     # vec2(1, 1)
vec2(1, 2) < vec2(2, 2)     # vec2(1, 0)
vec2(1, 2) < vec2(0, 0)     # vec2(0, 0)

vec2(1, 2) <= vec2(5, 5)    # vec2(1, 1)
vec2(1, 2) <= vec2(2, 2)    # vec2(1, 1)
vec2(1, 2) <= vec2(0, 0)    # vec2(0, 0)

vec2(1, 2) > vec2(5, 5)     # vec2(0, 0)
vec2(1, 2) > vec2(2, 2)     # vec2(0, 0)
vec2(1, 2) > vec2(0, 0)     # vec2(1, 1)

vec2(1, 2) >= vec2(5, 5)    # vec2(0, 0)
vec2(1, 2) >= vec2(2, 2)    # vec2(0, 1)
vec2(1, 2) >= vec2(0, 0)    # vec2(1, 1)
 ```  
### iter  
You can generate an iterable from vectors using ``` iter() ```\.  
``` Python
v  = vec2(1, 2)
it = iter(v)
print(next(it)) # prints 1.0
print(next(it)) # prints 2.0
 ```  
  
### hash  
You can generate a hash value for vectors using ``` hash() ```  
Example:  
``` Python
>>> v = vec2()
>>> hash(v)
-1952026010959490761
>>> v2 = vec2(1, 2)
>>> hash(v2)
8639716006723752019
>>> v3 = v2 * 0
>>> hash(v3)
-1952026010959490761
 ```