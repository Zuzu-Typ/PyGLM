[//]: # (generated using SlashBack 0.2.0)

  
1.  [Initialization](#Initialization)  
    *  [with no arguments](#initialization-with-no-arguments)  
    *  [all components with numbers](#Initializing-all-components-with-numbers)  
    *  [copying a quaternion](#Copying-a-quaternion)  
    *  [with vectors](#Initializing-quaternions-with-vectors)  
    *  [with vectors and numbers](#Constructing-vectors-from-other-vectors-and-numbers)  
    *  [Lists \(and other iterables\)](#lists-and-other-iterables)  
    *  [Buffer protocol \(numpy, bytes\)](#objects-that-support-the-buffer-protocol-numpy-bytes)  
2.  [Members](#Members)  
3.  [Methods](#Methods)  
    *  [The copy protocol](#the-copy-protocol)  
    *  [To list / tuple](#to-list--tuple)  
4.  [Operators](#Operators)  
    *  [add](#add--operator)  
    *  [sub](#sub--operator)  
    *  [mul](#mul--operator)  
    *  [div](#div--operator)  
    *  [mod](#mod--operator)  
    *  [floordiv](#floordiv--operator)  
    *  [divmod](#divmod)  
    *  [pow](#pow--operator)  
    *  [len](#len)  
    *  [getitem and setitem](#getitem-and-setitem--operator)  
    *  [contains](#contains-in-operator)  
    *  [richcompare](#richcompare-eg--operator)  
    *  [iter](#iter)  
  
## Initialization  
There are a few different ways of constructing a quaternion\.&nbsp;&nbsp;  
#### Initialization with no arguments  
Initializing a quaternion without any additional arguments will set the scalar part \(``` w ```\) to 1 and the vector parts \(``` x, y, z ```\) to 0 \(of the respective type\)\.&nbsp;&nbsp;  
Example:  
``` Python
glm.quat() # returns quaternion (1 + 0i + 0j + 0k)
 ```  
#### Initializing all components with numbers  
A quaternion can be initialized with 4 numbers, which will be copied \(or may be converted\) to their components\.&nbsp;&nbsp;  
Example:  
``` Python
glm.quat(1, 2, 3, 4) # returns quaternion (1 + 2i + 3j + 4k)
 ```  
Note: For some reason the creator of glm decided to express quaternions as ``` (xi + yj + zk + w) ``` or ``` (x, y, z, w) ``` respectively\.  
Thus, the string representation of quaternions is also in this order\. I might change this in the future\.  
#### Copying a quaternion  
A copy of a quaternion can be obtained by initializing a quaternion with another instance of a quaternion\.&nbsp;&nbsp;  
I\.e\. ``` glm.quat(glm.quat(1, 2, 3, 4)) ``` returns quaternion ``` (2i + 3j + 4k + 1) ```&nbsp;&nbsp;  
This is what's known as the copy constructor\.  
#### Initializing quaternions with vectors  
##### Initialization with a scalar and a vector  
You can initialize the scalar part \(``` w ```\) of the quaternion with a number and the vector part \(``` x, y, z ```\) with a ``` vec3 ``` \(or ``` dvec3 ``` respectively\)\.  
Example:  
``` Python
glm.quat(1, glm.vec3(2, 3, 4)) # returns quaternion (1 + 2i + 3j + 4k)
 ```  
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
\(if you do not need this functionality, you might want to use PyGLM\_FAST \- see Building PyGLM\)  
  
### Objects that support the buffer protocol \(numpy, bytes\)  
A few objects in Python support a functionality called the buffer protocol\.&nbsp;&nbsp;  
One such example would be the Python ``` bytes ``` type or ``` numpy.array ```\.&nbsp;&nbsp;  
PyGLM also supports this protocol and thus can be converted to or from any other object that supports it, granted it's in a fitting format\.&nbsp;&nbsp;  
e\.g\. ``` bytes(glm.u8vec2(1,2)) ``` returns ``` b'\x01\x02' ```&nbsp;&nbsp;  
and ``` glm.u8vec2(b'\x01\x02') ``` returns an 8\-bit unsigned integer vector ``` (1, 2) ```  
  
or ``` glm.vec3(numpy.array([4,5,6])) ``` returns vector ``` (4.0, 5.0, 6.0) ```&nbsp;&nbsp;  
and ``` numpy.array(glm.vec3(4, 5, 6)) ``` returns ``` array([4., 5., 6.], dtype=float32) ```&nbsp;&nbsp;  
  
Note: objects that use the buffer protocol *may* request a reference instead of a copy of the object, meaning that if you change the 'copy', you'll also change the original\.&nbsp;&nbsp;  
  
\(if you do not need this functionality, you might want to use PyGLM\_FAST \- see Building PyGLM\)  
  
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
  
### To list / tuple  
Any vector type has a ``` to_list() ``` and a ``` to_tuple() ``` function, which return's the vector's data represented as a list or tuple respectively\.  
  
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