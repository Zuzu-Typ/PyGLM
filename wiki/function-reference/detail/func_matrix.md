[//]: # (generated using SlashBack 0.2.0)

  
# func\_matrix methods  
The following methods are all part of the **func\_matrix methods**\.  
It contains GLSL matrix functions\.  
## Table of contents  
  
* [**determinant** function](#determinant-function)  
* [**inverse** function](#inverse-function)  
* [**matrixCompMult** function](#matrixcompmult-function)  
* [**outerProduct** function](#outerproduct-function)  
* [**transpose** function](#transpose-function)  
  
### determinant\(\) function  
#### <code>glm.<code>**determinant**(**m**: *matSxS*) -\> *float*</code></code>  
&emsp;&emsp;Return the determinant of a squared matrix\.  
  
### inverse\(\) function  
#### <code>glm.<code>**inverse**(**m**: *matSxS*) -\> *matSxS*</code></code>  
&emsp;&emsp;Return the inverse of a squared matrix\.  
  
#### <code>glm.<code>**inverse**(**q**: *quat*) -\> *quat*</code></code>  
&emsp;&emsp;Return the inverse of a quaternion\.  
  
### matrixCompMult\(\) function  
#### <code>glm.<code>**matrixCompMult**(**x**: *matNxM*, **y**: *matNxM*) -\> *matNxM*</code></code>  
&emsp;&emsp;Multiply matrix ``` x ``` by matrix ``` y ``` component\-wise, i\.e\., ``` result[i][j] ``` is the scalar product of  
&emsp;&emsp;``` x[i][j] ``` and ``` y[i][j] ```\.  
  
### outerProduct\(\) function  
#### <code>glm.<code>**outerProduct**(**c**: *vecC*, **r**: *vecR*) -\> *matRxC*</code></code>  
&emsp;&emsp;Treats the first parameter ``` c ``` as a column vector and the second parameter ``` r ``` as a row vector  
&emsp;&emsp;and does a linear algebraic matrix multiply ``` c * r ```\.  
  
### transpose\(\) function  
#### <code>glm.<code>**transpose**(**x**: *matNxM*) -\> *matMxN*</code></code>  
&emsp;&emsp;Returns the transposed matrix of ``` x ```\.  
  
