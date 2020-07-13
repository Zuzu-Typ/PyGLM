[//]: # (generated using SlashBack 0.2.0)

  
1.  [Initialization](#Initialization)  
    *  [with no arguments](#initialization-with-no-arguments)  
    *  [all components with numbers](#Initializing-all-components-with-numbers)  
    *  [copying a quaternion](#Copying-a-quaternion)  
    *  [converting a quaternion](#Converting-a-quaternion)  
    *  [with vectors](#Initializing-quaternions-with-vectors)  
        *  [scalar and vector](#Initialization-with-a-scalar-and-a-vector)  
        *  [two vec3s](#Constructing-quaternions-from-two-vec3s)  
        *  [euler angles](#Constructing-quaternions-from-euler-angles)  
    *  [conversion from mat3 or mat4](#Converting-a-mat3-or-mat4-to-a-quaternion)  
    *  [lists \(and other iterables\)](#lists-and-other-iterables)  
    *  [buffer protocol \(numpy, bytes\)](#objects-that-support-the-buffer-protocol-numpy-bytes)  
2.  [Members](#Members)  
3.  [Methods](#Methods)  
    *  [The copy protocol](#the-copy-protocol)  
4.  [Operators](#Operators)  
    *  [add](#add--operator)  
    *  [sub](#sub--operator)  
    *  [mul](#mul--operator)  
        *  [quat \* quat](#quat--quat)  
        *  [quat \* scalar](#quat--scalar)  
        *  [quat \* vec](#quat--vec)  
    *  [div](#div--operator)  
    *  [len](#len)  
    *  [getitem and setitem](#getitem-and-setitem--operator)  
    *  [contains](#contains-in-operator)  
    *  [richcompare](#richcompare-eg--operator)  
    *  [iter](#iter)  
    *  [hash](#hash)  
  
## Initialization  
There are a few different ways of constructing a quaternion\.&nbsp;&nbsp;  
#### Initialization with no arguments  
Initializing a quaternion without any additional arguments will set the scalar part \(``` w ```\) to 1 and the vector parts \(``` x, y, z ```\) to 0 \(of the respective type\)\.&nbsp;&nbsp;  
Example:  
``` Python
quat() # returns quaternion (1 + 0i + 0j + 0k), where i, j and k are imaginary numbers
 ```  
*Note: The component order of quaternions were inconsistent in PyGLM versions prior to 2\.0\.0\.*  
#### Initializing all components with numbers  
A quaternion can be initialized with 4 numbers, which will be copied \(or may be converted\) to their components\.&nbsp;&nbsp;  
Example:  
``` Python
quat(1, 2, 3, 4) # returns quaternion (1 + 2i + 3j + 4k)
 ```  
#### Copying a quaternion  
A copy of a quaternion can be obtained by initializing a quaternion with another instance of a quaternion\.&nbsp;&nbsp;  
I\.e\. ``` quat(quat(1, 2, 3, 4)) ``` returns quaternion ``` (1 + 2i + 3j + 4k) ```&nbsp;&nbsp;  
This is what's known as the copy constructor\.  
#### Converting a quaternion  
To convert a quaternion from one data type to another, the target data type can simply be initialized with the source\.  
``` Python
>>> quat(dquat(1, 2, 3, 4))
quat( 1, 2, 3, 4 )
 ```  
*Note: This feature may not be available in PyGLM versions prior to 2\.0\.0*  
#### Initializing quaternions with vectors  
##### Initialization with a scalar and a vector  
You can initialize the scalar part \(``` w ```\) of the quaternion with a number and the vector part \(``` x, y, z ```\) with a ``` vec3 ``` \(or ``` dvec3 ``` respectively\)\.  
Example:  
``` Python
quat(1, vec3(2, 3, 4)) # returns quaternion (1 + 2i + 3j + 4k)
 ```  
##### Constructing quaternions from two vec3s  
You can construct a quaternion from two length 3 vectors, which will return a rotation quaternion, that equals the rotation around an orthagonal axis between first direction to the other\.  
Example:  
``` Python
>>> a = vec3(1, -2, 3)
>>> b = vec3(-4, 5, -6)
>>> q = quat(a, b) # rotation from b to a
>>> b_rot = b * q
>>> print(normalize(a))
vec3(  0.267261, -0.534522,  0.801784 )
>>> print(normalize(b_rot))
vec3(  0.267261, -0.534523,  0.801784 ) # there may be a few rounding differences
 ```  
##### Constructing quaternions from euler angles  
You can create a quaternion from a single ``` vec3 ```, containing 3 angles known as euler angles\.  
They have the following structure: ``` vec3(pitch, yaw, roll) ```, where each angle is a radian value\.  
  
* Pitch is the rotation arount the X\-axis  
* Yaw is the rotation arount the Y\-axis  
* Roll is the rotation arount the Z\-axis  
  
Example:  
``` Python
>>> euler_angles = radians(vec3(10, 20, 30))
>>> q = quat(euler_angles)
>>> degrees(pitch(q))
9.999998855319275
>>> degrees(yaw(q))
20.000001125733135
>>> degrees(roll(q))
30.000000834826057
 ```  
#### Converting a mat3 or mat4 to a quaternion  
You can initialize a quaternion with a mat3x3 \(or mat4x4, which will be converted to a mat3x3\), to get a quaternion with the same rotational effect\.  
### Lists \(and other iterables\)  
Instead of using quaternions, vectors or matrices to initialize vectors, you can also use lists and other iterables\.&nbsp;&nbsp;  
In most cases, ``` (1, 2, 3) ``` will be interpreted as a ``` vec3(1, 2, 3) ``` of a fitting type\.  
``` (1, 2, 3, 4) ``` may be interpreted as a ``` vec4(1, 2, 3, 4) ``` or a ``` quat(1, 2, 3, 4) ```, depending on the circumstances \- though usually the vector representation is preferred\.  
``` ((1, 2), (3, 4)) ``` will be interpreted as a ``` mat2(1, 2, 3, 4) ```\.  
  
*Note: This feature may not be supported on PyGLM versions prior to 2\.0\.0, so please handle with care\.*  
  
### Objects that support the buffer protocol \(numpy, bytes\)  
A few objects in Python support a functionality called the buffer protocol\.&nbsp;&nbsp;  
One such example would be the Python ``` bytes ``` type or ``` numpy.array ```\.&nbsp;&nbsp;  
PyGLM also supports this protocol and thus can be converted to or from any other object that supports it, granted it's in a fitting format\.&nbsp;&nbsp;  
E\.g\. ``` numpy.array(glm.quat(1, 2, 3, 4)) ``` returns ``` array([1., 2., 3., 4.], dtype=float32) ```&nbsp;&nbsp;  
and ``` glm.quat(numpy.array([1., 2., 3., 4.], dtype="float32")) ``` returns ``` quat(1, 2, 3, 4) ```\.  
  
*Note: objects that use the buffer protocol may request a reference instead of a copy of the object, meaning that if you change the 'copy', you'll also change the original\.*&nbsp;&nbsp;  
  
## Members  
A quaternion has a member for each of it's components\.&nbsp;&nbsp;  

Member|Description
-|-
w|The scalar part
x|The first vector part
y|The second vector part
z|The last vector part
  
  
Quaternions do not support swizzling\.  
  
## Methods  
Any quaternion type implements the following methods:  
  

Method|Description
-|-
to\_list|Returns a list containing each component of the quaternion
to\_tuple|Returns a tuple containing each component of the quaternion
  
  
### The copy protocol  
Quaternions support the copy protocol \(see [here](https://docs.python.org/3/library/copy.html)\)\.&nbsp;&nbsp;  
You can use ``` copy.copy(<quat>) ``` or ``` copy.deepcopy(<quat>) ``` to get a copy of a quaternion\.  
  
## Operators  
Quaternions support a bunch of operators\.  
### add \(``` + ``` operator\)  
Quaternions support component\-wise addition with other quaternions\.&nbsp;&nbsp;  
``` Python
sum = quat(1, 2, 3, 4) + quat(5, 6, 7, 8) # returns quat(6, 8, 10, 12)
 ```  
### sub \(``` - ``` operator\)  
Quaternions support component\-wise subtraction with other quaternions\.&nbsp;&nbsp;  
``` Python
diff = quat(1, 2, 3, 4) + quat(5, 6, 7, 8) # returns quat(-4, -4, -4, -4)
 ```  
### mul \(``` * ``` operator\)  
Quaternions support multiplication with other quaternions, vectors and scalars\.&nbsp;&nbsp;  
  
##### quat \* quat  
Multiplying two quaternions will return their cross product\.  
The cross product of ``` quat(s1, v1) ``` and ``` quat(s2, v2) ``` \(with v1 and v2 being length 3 vectors\) is defined as:  
``` Python
quat(
	s1 * s2 - dot(v1, v2),
	s1 * v2 + s2 * v1 + cross(v1, v2)
)
 ```  
Example:  
``` Python
>>> quat(1, 2, 3, 4) * quat(5, 6, 7, 8)
quat( -60, 12, 30, 24 )
>>> cross(quat(1, 2, 3, 4), quat(5, 6, 7, 8))
quat( -60, 12, 30, 24 )
 ```  
  
##### quat \* scalar  
Multiplying a quaternion with a scalar will scale each component by the given number\.  
``` Python
>>> quat(1, 2, 3, 4) * 2
quat( 2, 4, 6, 8 )
 ```  
  
##### quat \* vec  
Multiplying a quaternion by a vector \(vec3 or vec4\) will return a rotated vector\.  
If the vector is on the left side of the equasion, the result will be a vector rotated by the inverse of the quaternion\.  
``` Python
>>> q = quat(radians(vec3(0,90,0))) # yaw = 90°
>>> v = vec3(1,0,0)
>>> q * v
vec3( 5.96046e-08, 0, -1 )
>>> v * q
vec3( -1.19209e-07, 0, 1 )
 ```  
### div \(``` / ``` operator\)  
Quaternions support component wise, right handside division with scalars \(numbers\)\.&nbsp;&nbsp;  
``` Python
quot1 = quat(1, 2, 3, 4) / 2 # returns quat(0.5, 1, 1.5, 2)
 ```  
### len  
The length of a quaternion \(always 4\) can be queried using ``` len() ```\.  
``` Python
quat_length = len(quat()) # returns 4
 ```  
### getitem and setitem \(``` [] ``` operator\)  
You can get the values of a quaternion using indices\.  
``` Python
q = quat(1, 2, 3, 4)
print(q[0]) # prints 1.0
print(q[1]) # prints 2.0
print(q[2]) # prints 3.0
print(q[3]) # prints 4.0
 ```  
Likewise you can set the values\.  
``` Python
q    = quat(1, 2, 3, 4)
q[0] = 9
print(q.w) # prints 9.0
 ```  
### contains \(``` in ``` operator\)  
You can query wether or not a value is contained by a quaternion using the ``` in ``` operator\.  
``` Python
q     = quat(1, 2, 3, 4)
true  = 2    in q
false = 2.01 in q
 ```  
### richcompare \(e\.g\. ``` == ``` operator\)  
You can compare quaternions using the equality richcompare operators:  
``` Python
quat(1, 0, 0, 0) == quat()            # True
quat(1, 2, 3, 4) == dquat(1, 2, 3, 4) # False
quat(1, 2, 3, 4) == vec4(1, 2, 3, 4)  # False

vec2(1, 2) != vec2(1, 2)    # False
vec2(1, 2) != vec2(2, 2)    # True
vec2(1, 2) != vec3(1, 2, 3) # True
 ```  
### iter  
You can generate an iterable from quaternions using ``` iter() ```\.  
``` Python
q  = quat(1, 2, 3, 4)
it = iter(q)
print(next(it)) # prints 1.0
print(next(it)) # prints 2.0
print(next(it)) # prints 3.0
print(next(it)) # prints 4.0
 ```  
  
### hash  
You can generate a hash value for quaternions using ``` hash() ```  
Example:  
``` Python
>>> q = quat()
>>> hash(q)
4797573974374731128
>>> q2 = quat(1, 2, 3, 4)
>>> hash(q2)
8060046874292968317
 ```