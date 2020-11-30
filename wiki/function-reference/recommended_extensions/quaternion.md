[//]: # (generated using SlashBack 0.2.0)

  
# quaternion methods  
The following methods are all part of the **quaternion methods**\.  
Defines a templated quaternion type and several quaternion operations\.  
## Table of contents  
  
* [**eulerAngles** function](#eulerangles-function)  
* [**mat3\_cast** function](#mat3_cast-function)  
* [**mat4\_cast** function](#mat4_cast-function)  
* [**pitch** function](#pitch-function)  
* [**quatLookAt** function](#quatlookat-function)  
* [**quatLookAtLH** function](#quatlookatlh-function)  
* [**quatLookAtRH** function](#quatlookatrh-function)  
* [**quat\_cast** function](#quat_cast-function)  
* [**roll** function](#roll-function)  
* [**yaw** function](#yaw-function)  
  
### eulerAngles\(\) function  
#### <code>glm.<code>**eulerAngles**(**x**: *quat*) -\> *vec3*</code></code>  
&emsp;&emsp;Returns euler angles, pitch as x, yaw as y, roll as z\. The result is expressed in radians\.  
  
### mat3\_cast\(\) function  
#### <code>glm.<code>**mat3_cast**(**x**: *quat*) -\> *mat3*</code></code>  
&emsp;&emsp;Converts a quaternion to a 3 x 3 matrix\.  
  
### mat4\_cast\(\) function  
#### <code>glm.<code>**mat4_cast**(**x**: *quat*) -\> *mat4*</code></code>  
&emsp;&emsp;Converts a quaternion to a 4 x 4 matrix\.  
  
### pitch\(\) function  
#### <code>glm.<code>**pitch**(**x**: *quat*) -\> *float*</code></code>  
&emsp;&emsp;Returns pitch value of euler angles expressed in radians\.  
  
### quatLookAt\(\) function  
#### <code>glm.<code>**quatLookAt**(**direction**: *vec3*, **up**: *vec3*) -\> *quat*</code></code>  
&emsp;&emsp;See quatLookAtRH\.  
  
### quatLookAtLH\(\) function  
#### <code>glm.<code>**quatLookAtLH**(**direction**: *vec3*, **up**: *vec3*) -\> *quat*</code></code>  
&emsp;&emsp;Build a left\-handed look at quaternion\.  
  
### quatLookAtRH\(\) function  
#### <code>glm.<code>**quatLookAtRH**(**direction**: *vec3*, **up**: *vec3*) -\> *quat*</code></code>  
&emsp;&emsp;Build a right\-handed look at quaternion\.  
  
### quat\_cast\(\) function  
#### <code>glm.<code>**quat_cast**(**x**: *mat3*) -\> *quat*</code></code>  
&emsp;&emsp;Converts a pure rotation 3 x 3 matrix to a quaternion\.  
  
#### <code>glm.<code>**quat_cast**(**x**: *mat4*) -\> *quat*</code></code>  
&emsp;&emsp;Converts a pure rotation 4 x 4 matrix to a quaternion\.  
  
### roll\(\) function  
#### <code>glm.<code>**roll**(**x**: *quat*) -\> *float*</code></code>  
&emsp;&emsp;Returns roll value of euler angles expressed in radians\.  
  
### yaw\(\) function  
#### <code>glm.<code>**yaw**(**x**: *quat*) -\> *float*</code></code>  
&emsp;&emsp;Returns yaw value of euler angles expressed in radians\.  
  
