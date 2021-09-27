[//]: # (generated using SlashBack 0.2.0)

# Using Matrices  
  
1.  [Initialization](#initialization)  
    *  [with no arguments](#initialization-with-no-arguments)  
    *  [with single number](#initialization-with-a-single-number)  
    *  [with quaternion](#initialization-with-a-quaternion)  
    *  [with custom diagonal values](#initializing-the-matrix-diagonal-with-custom-values)  
    *  [all components with numbers](#initializing-all-components-with-numbers)  
    *  [copying a matrix](#copying-a-matrix)  
    *  [with vectors](#constructing-matrices-from-vectors)  
    *  [Lists \(and other iterables\)](#lists-and-other-iterables)  
    *  [Buffer protocol \(numpy, bytes\)](#objects-that-support-the-buffer-protocol-numpy-bytes)  
2.  [Methods](#methods)  
    *  [The copy protocol](#the-copy-protocol)  
    *  [Pickling](#pickling)  
    *  [To list / tuple](#to-list--tuple)  
    *  [To and from bytes](#to-and-from-bytes)  
3.  [Operators](#operators)  
    *  [add](#add--operator)  
    *  [sub](#sub--operator)  
    *  [mul](#mul--operator)  
    *  [matmul](#matmul--operator)  
    *  [div](#div--operator)  
    *  [len](#len)  
    *  [getitem and setitem](#getitem-and-setitem--operator)  
    *  [contains](#contains-in-operator)  
    *  [richcompare](#richcompare-eg--operator)  
    *  [iter](#iter)  
    *  [hash](#hash)  
  
## Initialization  
Matrices can be constructed in quite a few different ways\.  
#### Initialization with no arguments  
Initializing a matrix without any additional arguments will return an identity matrix, meaning that it's values are set to ``` 1 ``` where column and row indices are equal and set to ``` 0 ``` otherwise\.&nbsp;&nbsp;  
This results in a diagonal line of ones from top left to bottom right\.&nbsp;&nbsp;  
Example:  
``` Python
>>> print(glm.mat2())
[            1 ][            0 ]
[            0 ][            1 ]

>>> print(glm.mat4())
[            1 ][            0 ][            0 ][            0 ]
[            0 ][            1 ][            0 ][            0 ]
[            0 ][            0 ][            1 ][            0 ]
[            0 ][            0 ][            0 ][            1 ]

>>> print(glm.mat2x4())
[            1 ][            0 ]
[            0 ][            1 ]
[            0 ][            0 ]
[            0 ][            0 ]
 ```  
#### Initialization with a single number  
Initializing a matrix with a single number returns a matrix similar to the identity matrices shown above\.&nbsp;&nbsp;  
The only difference is that instead of setting equal column and row indices to ``` 1 ```, they're set to the provided number\.&nbsp;&nbsp;  
Example:  
``` Python
>>> print(glm.mat2(3))
[            3 ][            0 ]
[            0 ][            3 ]

>>> print(glm.mat4(0))
[            0 ][            0 ][            0 ][            0 ]
[            0 ][            0 ][            0 ][            0 ]
[            0 ][            0 ][            0 ][            0 ]
[            0 ][            0 ][            0 ][            0 ]

>>> print(glm.mat2x4(1.5))
[          1.5 ][            0 ]
[            0 ][          1.5 ]
[            0 ][            0 ]
[            0 ][            0 ]
 ```  
#### Initialization with a quaternion  
Initializing a 3x3 or 4x4 matrix with a quaternion yields a matrix with the same basic rotational properties as the quaternion\.  
Example:  
``` Python
>>> q = glm.quat(glm.vec3(0, 0, glm.radians(90))) # rotate 90 degrees around the Z axis
>>> print(glm.mat4(q))
[  5.96046e-08 ][           -1 ][            0 ][            0 ]
[            1 ][  5.96046e-08 ][            0 ][            0 ]
[            0 ][            0 ][            1 ][            0 ]
[            0 ][            0 ][            0 ][            1 ]

>>> print(glm.rotate(glm.radians(90), glm.vec3(0, 0, 1)))
[ -4.37114e-08 ][           -1 ][            0 ][            0 ]
[            1 ][ -4.37114e-08 ][            0 ][            0 ]
[            0 ][            0 ][            1 ][            0 ]
[            0 ][            0 ][            0 ][            1 ]
 ```  
#### Initializing the matrix diagonal with custom values  
You can initialize a matrix' diagonal with custom values\.  
Example:  
``` Python
>>> print(glm.mat2(1, 2))
[            1 ][            0 ]
[            0 ][            2 ]

>>> print(glm.mat4(1, 2, 3, 4))
[            1 ][            0 ][            0 ][            0 ]
[            0 ][            2 ][            0 ][            0 ]
[            0 ][            0 ][            3 ][            0 ]
[            0 ][            0 ][            0 ][            4 ]

>>> print(glm.mat2x4(1, 2))
[            1 ][            0 ]
[            0 ][            2 ]
[            0 ][            0 ]
[            0 ][            0 ]
 ```  
i\.e\. a ``` matNxM ``` matrix can be initialized with ``` int(sqrt(N * M)) ``` numbers\.  
#### Initializing all components with numbers  
A matrix ``` matNxM ``` can be initialized with *N* x *M* numbers, which will be copied \(or may be converted\) to their respective components\.&nbsp;&nbsp;  
Example:  
``` Python
>>> print(glm.mat2(1, 2, 3, 4))
[            1 ][            3 ]
[            2 ][            4 ]

>>> print(glm.mat4(*range(16)))
[            0 ][            4 ][            8 ][           12 ]
[            1 ][            5 ][            9 ][           13 ]
[            2 ][            6 ][           10 ][           14 ]
[            3 ][            7 ][           11 ][           15 ]
 ```  
#### Copying a matrix  
A copy of a matrix can be obtained by initializing a matrix with an instance of a matrix\.&nbsp;&nbsp;  
i\.e\. ``` glm.mat2(glm.mat2(5, 2, 4, 3)) ``` returns matrix ``` ((5, 2), (4, 3)) ```&nbsp;&nbsp;  
This is what's known as the copy constructor\.  
#### Initializing matrices with other matrices  
You can initialize any matrix with another matrix \(as long as they have the same datatype or size\)\.&nbsp;&nbsp;  
Any values that don't fit into the new matrix are discarded and any values that aren't filled by the supplied matrix are padded up with values from the respective identity matrix\.&nbsp;&nbsp;  
Example:&nbsp;&nbsp;  
``` Python
>>> print(glm.mat4( glm.mat2(9, 8, 7, 6) ))
[            9 ][            7 ][            0 ][            0 ]
[            8 ][            6 ][            0 ][            0 ]
[            0 ][            0 ][            1 ][            0 ]
[            0 ][            0 ][            0 ][            1 ]

>>> m44 = glm.mat4(*range(16))
>>> print(m44)
[            0 ][            4 ][            8 ][           12 ]
[            1 ][            5 ][            9 ][           13 ]
[            2 ][            6 ][           10 ][           14 ]
[            3 ][            7 ][           11 ][           15 ]

>>> print(glm.mat2(m44))
[            0 ][            4 ]
[            1 ][            5 ]

>>> m32 = glm.mat3x2(6, 5, 4, 3, 2, 1)
>>> print(m32)
[            6 ][            4 ][            2 ]
[            5 ][            3 ][            1 ]

>>> print(glm.mat2x3(m32))
[            6 ][            4 ]
[            5 ][            3 ]
[            0 ][            0 ]

>>> print(glm.mat3(m32))
[            6 ][            4 ][            2 ]
[            5 ][            3 ][            1 ]
[            0 ][            0 ][            1 ]

>>> print(glm.imat2(glm.dmat2(7.9)))
[            7 ][            0 ]
[            0 ][            7 ]
 ```  
#### Constructing matrices from vectors  
You can construct a ``` matNxM ``` from *N* vectors of length *M*, if they share the same datatype\.  
Example:  
``` Python
>>> print(glm.mat2( glm.vec2(1, 2), glm.vec2(3, 4) )) # 2 vectors of length 2
[            1 ][            3 ]
[            2 ][            4 ]

>>> print(glm.mat2x4( glm.vec4(1, 2, 3, 4), glm.vec4(5, 6, 7, 8) )) # 2 vectors of length 4
[            1 ][            5 ]
[            2 ][            6 ]
[            3 ][            7 ]
[            4 ][            8 ]

>>> print(glm.mat4x2( glm.vec2(1, 2), glm.vec2(3, 4), glm.vec2(5, 6), glm.vec2(7, 8) )) # 4 vectors of length 2
[            1 ][            3 ][            5 ][            7 ]
[            2 ][            4 ][            6 ][            8 ]
 ```  
  
### Lists \(and other iterables\)  
Instead of using matrices, you can use matrix\-like lists / tuples in most cases\.  
For example, you can initialize a matrix with a matrix\-like tuple:  
``` Python
>>> print(glm.mat2( ((1, 2), (3, 4)) ))
[            1 ][            3 ]
[            2 ][            4 ]
 ```   
Or use it on one handside of a numeric operator:  
``` Python
>>> m22 = glm.mat2()
>>> print(m22)
[            1 ][            0 ]
[            0 ][            1 ]

>>> print(m22 + ((4, 3), (2, 1)))
[            5 ][            2 ]
[            3 ][            2 ]
 ```  
It is also accepted by most functions:  
``` Python
>>> print(glm.inverse( ((1,2),(3,4)) ))
[           -2 ][          1.5 ]
[            1 ][         -0.5 ]
 ```   
  
### Objects that support the buffer protocol \(numpy, bytes\)  
A few objects in Python support a functionality called the buffer protocol\.&nbsp;&nbsp;  
One such example would be the Python ``` bytes ``` type or ``` numpy.array ```\.&nbsp;&nbsp;  
PyGLM also supports this protocol and thus can be converted to or from any other object that supports it, granted it's in a fitting format\.&nbsp;&nbsp;  
Examples:  
``` Python
>>> narr = numpy.array(glm.mat4())
>>> print(narr)
[[1. 0. 0. 0.]
 [0. 1. 0. 0.]
 [0. 0. 1. 0.]
 [0. 0. 0. 1.]]
 
>>> print(glm.mat4(narr))
[            1 ][            0 ][            0 ][            0 ]
[            0 ][            1 ][            0 ][            0 ]
[            0 ][            0 ][            1 ][            0 ]
[            0 ][            0 ][            0 ][            1 ]
 ```  
  
*Note: objects that use the buffer protocol may request a reference instead of a copy of the object, meaning that if you change the 'copy', you'll also change the original\.*  
  
## Methods  
Any matrix type implements the following methods:  
  
### Length  
You can acquire the length of a matrix with the ``` length() ``` method\.  
It will give you the same result as the builtin ``` len(<matrix>) ``` method\.  
  
### The copy protocol  
Matrices support the copy protocol \(see [here](https://docs.python.org/3/library/copy.html)\)\.&nbsp;&nbsp;  
You can use ``` copy.copy(<matrix>) ``` or ``` copy.deepcopy(<matrix>) ``` to get a copy of a matrix\.  
  
### Pickling  
Matrices support [pickling](https://docs.python.org/3/library/pickle.html#module-interface) \(as of PyGLM 2\.0\.0\), which is Python's serialization method\.  
  
### To list / tuple  
Any matrix type has a ``` to_list() ``` and a ``` to_tuple() ``` function, which returns the matrix' data represented as a list or tuple respectively\.  
Example:  
``` Python
>>> print(glm.mat4().to_list())
[[1.0, 0.0, 0.0, 0.0], [0.0, 1.0, 0.0, 0.0], [0.0, 0.0, 1.0, 0.0], [0.0, 0.0, 0.0, 1.0]]

>>> print(glm.mat4().to_tuple())
((1.0, 0.0, 0.0, 0.0), (0.0, 1.0, 0.0, 0.0), (0.0, 0.0, 1.0, 0.0), (0.0, 0.0, 0.0, 1.0))
 ```  
  
  
### To and from bytes  
All matrices have a ``` to_bytes() ``` and a ``` from_bytes() ``` method, which allows for conversion of the matrix' data to and from bytes strings\.  
  
## Operators  
Matrix types support a bunch of operators\.  
### add \(``` + ``` operator\)  
Matrices support addition with other matrices and numbers\.  
Only matrices of the same shape and type can be used\.  
``` Python
sum1 = mat2(1, 2, 3, 4) + mat2(1, 0, 1, 0) # returns mat2(2, 2, 4, 4)
sum2 = mat2(1, 2, 3, 4) + 4                # returns mat2(5, 6, 7, 8)
 ```  
Note: Only square matrices allow for left side addition of numbers  
### sub \(``` - ``` operator\)  
Matrices support subtraction with other matrices and numbers\.&nbsp;&nbsp;  
``` Python
diff1 = mat2(1, 2, 3, 4) - mat2(1, 0, 1, 0) # returns mat2(0, 2, 2, 4)
diff2 = mat2(1, 2, 3, 4) - 4                # returns mat2(-3, -2, -1, 0)
 ```  
Note: Only square matrices allow for left side subtration of numbers  
### mul \(``` * ``` operator\)  
Matrices support multiplication with vectors, other matrices and numbers\.&nbsp;&nbsp;  
Multiplying a matrix with a number multiplies each component with that number\.  
``` Python
prod = mat2(1, 2, 3, 4) * 4 # returns mat2(4, 8, 12, 16)
 ```  
Multiplying a matrix with a vector is a bit more complex\.  
If you have a ``` matNxM ``` matrix, you can either  
left\-side multiply it with a length *M* vector and get a length *N* vector in return  
``` Python
prod1 = vec3(7, 8, 9) * mat2x3((1, 2, 3), (4, 5, 6))
# returns vec2(
#      7 * 1 + 8 * 2 + 9 * 3,
#      7 * 4 + 8 * 5 + 9 * 6
#    )
#    = vec2(50, 122)
prodx = vec4(a, b, c, d) * mat3x4((m00, m01, m02, m03), (m10, m11, m12, m13), (m20, m21, m22, m23))
# returns vec3(
#      a * m00 + b * m01 + c * m02 + d * m03,
#      a * m10 + b * m11 + c * m12 + d * m13,
#      a * m20 + b * m21 + c * m22 + d * m23
#    )
 ```  
or right\-side multiply it with a length *N* vector and get a length *M* vector in return\.  
``` Python
prod1 = mat2x3((1, 2, 3), (4, 5, 6)) * vec2(7, 8)
# returns vec3(
#      7 * 1 + 8 * 4,
#      7 * 2 + 8 * 5,
#      7 * 3 + 8 * 6
#    )
#    = vec3(39, 54, 69)
prodx = mat3x4((m00, m01, m02, m03), (m10, m11, m12, m13), (m20, m21, m22, m23)) * vec3(a, b, c)
# returns vec4(
#      a * m10 + b * m10 + c * m20,
#      a * m11 + b * m11 + c * m21,
#      a * m12 + b * m12 + c * m22,
#      a * m13 + b * m13 + c * m23
#    )
 ```  
For multiplication of square matrices with vectors using homogenous coordinates, PyGLM provides a shorthand:  
``` Python
m = rotate(radians(90), vec3(0, 1, 0)) # creates a 4x4 rotation matrix
v = vec3(1, 2, 3) # some 3D vector

# This is what you would normally have to do to apply the rotation to v:

v_rotated = vec3(m * vec4(v, 1)) # returns vec3( 3, 2, -1 )

# This is the shorthand:

v_rotated = m * v # returns vec3( 3, 2, -1 )
 ```  
Now for the most complex part\.  
Matrix\-matrix multiplication\.  
You can only multiply a ``` matAxB ``` with a ``` matCxA ``` matrix and it will return a ``` matCxB ``` matrix\.  
``` Python
mat2x3() * mat4x2() # returns a mat4x3
mat3x2() * mat2x4() # error - these matrices are incompatible
mat2x4() * mat2x4() # error - these matrices are incompatible
mat2x2() * mat2x2() # returns a mat2x2
mat3x3() * mat2x3() # returns a mat2x3
 ```  
The actual computation is a combination of multiplication and addition\.  
Okay, so this may be a bit difficult to grasp at first:  
Each component of the resulting matrix is the sum of each component of the *first* matrix' respective *row*   
multiplied by the components of the *second* matrix' respective *column*\.  
**Keep in mind, that glm's columns and rows are in the opposite order**, so this gets even more complicated\.  
Lets try to visualize it using an example:  
``` Python
>>> m24 = glm.mat2x4(1, 2, 3, 4, 5, 6, 7, 8)
>>> print(m24)
[            1 ][            5 ]
[            2 ][            6 ]
[            3 ][            7 ]
[            4 ][            8 ]
>>> m22 = glm.mat2(4, 3, 2, 1)
>>> print(m22)
[            4 ][            2 ]
[            3 ][            1 ]
>>> print(m24 * m22)
[           19 ][            7 ]
[           26 ][           10 ]
[           33 ][           13 ]
[           40 ][           16 ]

result = mat2x4(
		(
            m24[0, 0] * m22[0, 0] + m24[1, 0] * m22[0, 1],
            m24[0, 1] * m22[0, 0] + m24[1, 1] * m22[0, 1],
		    m24[0, 2] * m22[0, 0] + m24[1, 2] * m22[0, 1],
		    m24[0, 3] * m22[0, 0] + m24[1, 3] * m22[0, 1]
		),
		(
		    m24[0, 0] * m22[1, 0] + m24[1, 0] * m22[1, 1],
		    m24[0, 1] * m22[1, 0] + m24[1, 1] * m22[1, 1],
		    m24[0, 2] * m22[1, 0] + m24[1, 2] * m22[1, 1],
		    m24[0, 3] * m22[1, 0] + m24[1, 3] * m22[1, 1]
		)
	)
 ```   
### matmul \(``` @ ``` operator\)  
Has the same effects as the ``` * ``` operator\.  
### div \(``` / ``` operator\)  
Matrices support division with numbers, vectors and other matrices\.&nbsp;&nbsp;  
``` Python
quot = mat2(1, 2, 3, 4) / 2 # returns mat2(0.5, 1, 1.5, 2)
 ```  
Only square matrices can support division with other matrices and vectors\.  
If a matrix is divided by a vector or vice versa, the matrix is simply inversed and multiplied with that vector instead\.  
``` Python
>>> m22 = mat2(1, 2, 3, 4)
>>> v2 = vec2(5, 6)
>>> m22 / v2
vec2( -1, 2 )
>>> glm.inverse(m22) * v2
vec2( -1, 2 )
 ```  
Division with other matrices follows the same scheme\.  
The right handside matrix is inversed and then multiplied by the other matrix\.  
``` Python
>>> m22 = mat2(1, 2, 3, 4)
>>> m22 / mat2(8, 7, 6, 5)
mat2x2(( 8, 9 ), ( -9, -10 ))

>>> m22 * glm.inverse(mat2(8, 7, 6, 5))
mat2x2(( 8, 9 ), ( -9, -10 ))
 ```  
### len  
The length of a matrix \(i\.e\. the column count\) can be queried using ``` len() ```\.  
``` Python
mat_length = len(mat2x4()) # returns 2
 ```  
### getitem and setitem \(``` [] ``` operator\)  
You can get the values of a matrix using indices\.  
``` Python
m = mat2x3(1, 2, 3, 4, 5, 6)
print(m[0])    # prints mvec3(1, 2, 3)
print(m[1])    # prints mvec3(4, 5, 6)
print(m[0, 2]) # prints 3
print(m[1, 0]) # prints 4
 ```  
Note: *mvec is a special vector type, that references the values of the matrix it came from\.  
I\.e\. if you change the mvec's values, you will do so with the values of the matrix too\.*  
  
You can also set the values\.  
``` Python
>>> m    = mat2(1, 2, 3, 4)
>>> m[0] = vec2(5, 6)
>>> print(m)
[            5 ][            3 ]
[            6 ][            4 ]
 ```  
### contains \(``` in ``` operator\)  
You can query wether or not a value is contained by a matrix using the ``` in ``` operator\.  
``` Python
>>> m = mat2(1, 2, 3, 4)
>>> vec2(1, 2) in m
True
>>> vec2(2, 3) in m
False
>>> 3 in m
True
>>> 0 in m
False
 ```  
### richcompare \(e\.g\. ``` == ``` operator\)  
You can compare matrices using the equals and not\-equals richcompare operators:  
``` Python
mat2(1, 2, 3, 4) == mat2(1, 2, 3, 4)                # True
mat2(1, 2, 3, 4) == mat2(3, 4, 1, 2)                # False
mat2(1, 2, 3, 4) == mat3(1, 2, 3, 4, 5, 6, 7, 8, 9) # False

mat2(1, 2, 3, 4) != mat2(1, 2, 3, 4)                # False
mat2(1, 2, 3, 4) != mat2(3, 4, 1, 2)                # True
mat2(1, 2, 3, 4) != mat3(1, 2, 3, 4, 5, 6, 7, 8, 9) # True
 ```  
### iter  
You can generate an iterable from matrices using ``` iter() ```\.  
``` Python
m  = mat2(1, 2, 3, 4)
it = iter(m)
print(next(it)) # prints mvec2(1, 2)
print(next(it)) # prints mvec2(3, 4)
 ```  
  
### hash  
You can generate a hash value for matrices using ``` hash() ```  
Example:  
``` Python
>>> m = mat2()
>>> hash(m)
-8340327414932306126
>>> m2 = mat2(1, 2, 3, 4)
>>> hash(m2)
2533527020982565631
 ```