[//]: # (generated using SlashBack 0.2.0)

  
# matrix\_clip\_space methods  
The following methods are all part of the **matrix\_clip\_space methods**\.  
Defines functions that generate clip space transformation matrices\.  
## Table of contents  
  
* [**frustum** function](#frustum-function)  
* [**frustumLH** function](#frustumlh-function)  
* [**frustumLH\_NO** function](#frustumlh_no-function)  
* [**frustumLH\_ZO** function](#frustumlh_zo-function)  
* [**frustumNO** function](#frustumno-function)  
* [**frustumRH** function](#frustumrh-function)  
* [**frustumRH\_NO** function](#frustumrh_no-function)  
* [**frustumRH\_ZO** function](#frustumrh_zo-function)  
* [**frustumZO** function](#frustumzo-function)  
* [**infinitePerspective** function](#infiniteperspective-function)  
* [**infinitePerspectiveLH** function](#infiniteperspectivelh-function)  
* [**infinitePerspectiveRH** function](#infiniteperspectiverh-function)  
* [**ortho** function](#ortho-function)  
* [**orthoLH** function](#ortholh-function)  
* [**orthoLH\_NO** function](#ortholh_no-function)  
* [**orthoLH\_ZO** function](#ortholh_zo-function)  
* [**orthoNO** function](#orthono-function)  
* [**orthoRH** function](#orthorh-function)  
* [**orthoRH\_NO** function](#orthorh_no-function)  
* [**orthoRH\_ZO** function](#orthorh_zo-function)  
* [**orthoZO** function](#orthozo-function)  
* [**perspective** function](#perspective-function)  
* [**perspectiveFov** function](#perspectivefov-function)  
* [**perspectiveFovLH** function](#perspectivefovlh-function)  
* [**perspectiveFovLH\_NO** function](#perspectivefovlh_no-function)  
* [**perspectiveFovLH\_ZO** function](#perspectivefovlh_zo-function)  
* [**perspectiveFovNO** function](#perspectivefovno-function)  
* [**perspectiveFovRH** function](#perspectivefovrh-function)  
* [**perspectiveFovRH\_NO** function](#perspectivefovrh_no-function)  
* [**perspectiveFovRH\_ZO** function](#perspectivefovrh_zo-function)  
* [**perspectiveFovZO** function](#perspectivefovzo-function)  
* [**perspectiveLH** function](#perspectivelh-function)  
* [**perspectiveLH\_NO** function](#perspectivelh_no-function)  
* [**perspectiveLH\_ZO** function](#perspectivelh_zo-function)  
* [**perspectiveNO** function](#perspectiveno-function)  
* [**perspectiveRH** function](#perspectiverh-function)  
* [**perspectiveRH\_NO** function](#perspectiverh_no-function)  
* [**perspectiveRH\_ZO** function](#perspectiverh_zo-function)  
* [**perspectiveZO** function](#perspectivezo-function)  
* [**tweakedInfinitePerspective** function](#tweakedinfiniteperspective-function)  
  
### frustum\(\) function  
#### <code>glm.<code>**frustum**(**left**: *float*, **right**: *float*, **bottom**: *float*, **top**: *float*, **near**: *float*, **far**: *float*) -\> *fmat4x4*</code></code>  
&emsp;&emsp;See frustumRH\_NO\.  
  
### frustumLH\(\) function  
#### <code>glm.<code>**frustumLH**(**left**: *float*, **right**: *float*, **bottom**: *float*, **top**: *float*, **near**: *float*, **far**: *float*) -\> *fmat4x4*</code></code>  
&emsp;&emsp;See frustumLH\_NO\.  
  
### frustumLH\_NO\(\) function  
#### <code>glm.<code>**frustumLH_NO**(**left**: *float*, **right**: *float*, **bottom**: *float*, **top**: *float*, **near**: *float*, **far**: *float*) -\> *fmat4x4*</code></code>  
&emsp;&emsp;Creates a left handed frustum matrix\. The near and far clip planes correspond to z  
&emsp;&emsp;normalized device coordinates of \-1 and \+1 respectively\.  
&emsp;&emsp;\(OpenGL clip volume definition\)  
  
### frustumLH\_ZO\(\) function  
#### <code>glm.<code>**frustumLH_ZO**(**left**: *float*, **right**: *float*, **bottom**: *float*, **top**: *float*, **near**: *float*, **far**: *float*) -\> *fmat4x4*</code></code>  
&emsp;&emsp;Creates a left handed frustum matrix\. The near and far clip planes correspond to z  
&emsp;&emsp;normalized device coordinates of 0 and \+1 respectively\.  
&emsp;&emsp;\(Direct3D clip volume definition\)  
  
### frustumNO\(\) function  
#### <code>glm.<code>**frustumNO**(**left**: *float*, **right**: *float*, **bottom**: *float*, **top**: *float*, **near**: *float*, **far**: *float*) -\> *fmat4x4*</code></code>  
&emsp;&emsp;See frustumRH\_NO\.  
  
### frustumRH\(\) function  
#### <code>glm.<code>**frustumRH**(**left**: *float*, **right**: *float*, **bottom**: *float*, **top**: *float*, **near**: *float*, **far**: *float*) -\> *fmat4x4*</code></code>  
&emsp;&emsp;See frustumRH\_NO\.  
  
### frustumRH\_NO\(\) function  
#### <code>glm.<code>**frustumRH_NO**(**left**: *float*, **right**: *float*, **bottom**: *float*, **top**: *float*, **near**: *float*, **far**: *float*) -\> *fmat4x4*</code></code>  
&emsp;&emsp;Creates a right handed frustum matrix\. The near and far clip planes correspond to z  
&emsp;&emsp;normalized device coordinates of \-1 and \+1 respectively\.  
&emsp;&emsp;\(OpenGL clip volume definition\)  
  
### frustumRH\_ZO\(\) function  
#### <code>glm.<code>**frustumRH_ZO**(**left**: *float*, **right**: *float*, **bottom**: *float*, **top**: *float*, **near**: *float*, **far**: *float*) -\> *fmat4x4*</code></code>  
&emsp;&emsp;Creates a right handed frustum matrix\. The near and far clip planes correspond to z  
&emsp;&emsp;normalized device coordinates of 0 and \+1 respectively\.  
&emsp;&emsp;\(Direct3D clip volume definition\)  
  
### frustumZO\(\) function  
#### <code>glm.<code>**frustumZO**(**left**: *float*, **right**: *float*, **bottom**: *float*, **top**: *float*, **near**: *float*, **far**: *float*) -\> *fmat4x4*</code></code>  
&emsp;&emsp;See frustumRH\_ZO\.  
  
### infinitePerspective\(\) function  
#### <code>glm.<code>**infinitePerspective**(**fovy**: *float*, **aspect**: *float*, **near**: *float*) -\> *fmat4x4*</code></code>  
&emsp;&emsp;See infinitePerspectiveRH\.  
  
### infinitePerspectiveLH\(\) function  
#### <code>glm.<code>**infinitePerspectiveLH**(**fovy**: *float*, **aspect**: *float*, **near**: *float*) -\> *fmat4x4*</code></code>  
&emsp;&emsp;Creates a matrix for a left handed, symmetric perspective\-view frustum with far plane at  
&emsp;&emsp;infinite\.  
  
### infinitePerspectiveRH\(\) function  
#### <code>glm.<code>**infinitePerspectiveRH**(**fovy**: *float*, **aspect**: *float*, **near**: *float*) -\> *fmat4x4*</code></code>  
&emsp;&emsp;Creates a matrix for a right handed, symmetric perspective\-view frustum with far plane at  
&emsp;&emsp;infinite\.  
  
### ortho\(\) function  
#### <code>glm.<code>**ortho**(**left**: *float*, **right**: *float*, **bottom**: *float*, **top**: *float*) -\> *fmat4x4*</code></code>  
&emsp;&emsp;Creates a matrix for projecting two\-dimensional coordinates onto the screen\.  
  
#### <code>glm.<code>**ortho**(**left**: *float*, **right**: *float*, **bottom**: *float*, **top**: *float*, **zNear**: *float*, **zFar**: *float*) -\> *fmat4x4*</code></code>  
&emsp;&emsp;See orthoRH\_NO\.  
  
### orthoLH\(\) function  
#### <code>glm.<code>**orthoLH**(**left**: *float*, **right**: *float*, **bottom**: *float*, **top**: *float*, **zNear**: *float*, **zFar**: *float*) -\> *fmat4x4*</code></code>  
&emsp;&emsp;See orthoLH\_NO\.  
  
### orthoLH\_NO\(\) function  
#### <code>glm.<code>**orthoLH_NO**(**left**: *float*, **right**: *float*, **bottom**: *float*, **top**: *float*, **zNear**: *float*, **zFar**: *float*) -\> *fmat4x4*</code></code>  
&emsp;&emsp;Creates a matrix for an orthographic parallel viewing volume using left\-handed  
&emsp;&emsp;coordinates\. The nearand far clip planes correspond to z normalized device coordinates of  
&emsp;&emsp;\-1 and \+1 respectively\.  
&emsp;&emsp;\(OpenGL clip volume definition\)  
  
### orthoLH\_ZO\(\) function  
#### <code>glm.<code>**orthoLH_ZO**(**left**: *float*, **right**: *float*, **bottom**: *float*, **top**: *float*, **zNear**: *float*, **zFar**: *float*) -\> *fmat4x4*</code></code>  
&emsp;&emsp;Creates a matrix for an orthographic parallel viewing volume, using left\-handed  
&emsp;&emsp;coordinates\. The nearand far clip planes correspond to z normalized device  
&emsp;&emsp;coordinates of 0 and \+1 respectively\.  
&emsp;&emsp;\(Direct3D clip volume definition\)  
  
### orthoNO\(\) function  
#### <code>glm.<code>**orthoNO**(**left**: *float*, **right**: *float*, **bottom**: *float*, **top**: *float*, **zNear**: *float*, **zFar**: *float*) -\> *fmat4x4*</code></code>  
&emsp;&emsp;See orthoRH\_NO\.  
  
### orthoRH\(\) function  
#### <code>glm.<code>**orthoRH**(**left**: *float*, **right**: *float*, **bottom**: *float*, **top**: *float*, **zNear**: *float*, **zFar**: *float*) -\> *fmat4x4*</code></code>  
&emsp;&emsp;See orthoRH\_NO\.  
  
### orthoRH\_NO\(\) function  
#### <code>glm.<code>**orthoRH_NO**(**left**: *float*, **right**: *float*, **bottom**: *float*, **top**: *float*, **zNear**: *float*, **zFar**: *float*) -\> *fmat4x4*</code></code>  
&emsp;&emsp;Creates a matrix for an orthographic parallel viewing volume using right\-handed  
&emsp;&emsp;coordinates\. The nearand far clip planes correspond to z normalized device coordinates of  
&emsp;&emsp;\-1 and \+1 respectively\.  
&emsp;&emsp;\(OpenGL clip volume definition\)  
  
### orthoRH\_ZO\(\) function  
#### <code>glm.<code>**orthoRH_ZO**(**left**: *float*, **right**: *float*, **bottom**: *float*, **top**: *float*, **zNear**: *float*, **zFar**: *float*) -\> *fmat4x4*</code></code>  
&emsp;&emsp;Creates a matrix for an orthographic parallel viewing volume, using right\-handed  
&emsp;&emsp;coordinates\. The nearand far clip planes correspond to z normalized device  
&emsp;&emsp;coordinates of 0 and \+1 respectively\.  
&emsp;&emsp;\(Direct3D clip volume definition\)  
  
### orthoZO\(\) function  
#### <code>glm.<code>**orthoZO**(**left**: *float*, **right**: *float*, **bottom**: *float*, **top**: *float*, **zNear**: *float*, **zFar**: *float*) -\> *fmat4x4*</code></code>  
&emsp;&emsp;See orthoRH\_ZO\.  
  
### perspective\(\) function  
#### <code>glm.<code>**perspective**(**fovy**: *float*, **aspect**: *float*, **near**: *float*, **far**: *float*) -\> *fmat4x4*</code></code>  
&emsp;&emsp;See perspectiveRH\_NO\.  
  
### perspectiveFov\(\) function  
#### <code>glm.<code>**perspectiveFov**(**fov**: *float*, **width**: *float*, **height**: *float*, **near**: *float*, **far**: *float*) -\> *fmat4x4*</code></code>  
&emsp;&emsp;See perspectiveFovRH\_NO\.  
  
### perspectiveFovLH\(\) function  
#### <code>glm.<code>**perspectiveFovLH**(**fov**: *float*, **width**: *float*, **height**: *float*, **near**: *float*, **far**: *float*) -\> *fmat4x4*</code></code>  
&emsp;&emsp;See perspectiveFovLH\_NO\.  
  
### perspectiveFovLH\_NO\(\) function  
#### <code>glm.<code>**perspectiveFovLH_NO**(**fov**: *float*, **width**: *float*, **height**: *float*, **near**: *float*, **far**: *float*) -\> *fmat4x4*</code></code>  
&emsp;&emsp;Builds a perspective projection matrix based on a field of view using left\-handed  
&emsp;&emsp;coordinates\. The nearand far clip planes correspond to z normalized device coordinates of  
&emsp;&emsp;\-1 and \+1 respectively\. \(OpenGL clip volume definition\)  
  
### perspectiveFovLH\_ZO\(\) function  
#### <code>glm.<code>**perspectiveFovLH_ZO**(**fov**: *float*, **width**: *float*, **height**: *float*, **near**: *float*, **far**: *float*) -\> *fmat4x4*</code></code>  
&emsp;&emsp;Builds a perspective projection matrix based on a field of view using left\-handed  
&emsp;&emsp;coordinates\. The nearand far clip planes correspond to z normalized device coordinates of  
&emsp;&emsp;0 and \+1 respectively\. \(Direct3D clip volume definition\)  
  
### perspectiveFovNO\(\) function  
#### <code>glm.<code>**perspectiveFovNO**(**fov**: *float*, **width**: *float*, **height**: *float*, **near**: *float*, **far**: *float*) -\> *fmat4x4*</code></code>  
&emsp;&emsp;See perspectiveFovRH\_NO\.  
  
### perspectiveFovRH\(\) function  
#### <code>glm.<code>**perspectiveFovRH**(**fov**: *float*, **width**: *float*, **height**: *float*, **near**: *float*, **far**: *float*) -\> *fmat4x4*</code></code>  
&emsp;&emsp;See perspectiveFovRH\_NO\.  
  
### perspectiveFovRH\_NO\(\) function  
#### <code>glm.<code>**perspectiveFovRH_NO**(**fov**: *float*, **width**: *float*, **height**: *float*, **near**: *float*, **far**: *float*) -\> *fmat4x4*</code></code>  
&emsp;&emsp;Builds a perspective projection matrix based on a field of view using right\-handed  
&emsp;&emsp;coordinates\. The nearand far clip planes correspond to z normalized device coordinates of  
&emsp;&emsp;\-1 and \+1 respectively\. \(OpenGL clip volume definition\)  
  
### perspectiveFovRH\_ZO\(\) function  
#### <code>glm.<code>**perspectiveFovRH_ZO**(**fov**: *float*, **width**: *float*, **height**: *float*, **near**: *float*, **far**: *float*) -\> *fmat4x4*</code></code>  
&emsp;&emsp;Builds a perspective projection matrix based on a field of view using right\-handed  
&emsp;&emsp;coordinates\. The nearand far clip planes correspond to z normalized device coordinates of  
&emsp;&emsp;0 and \+1 respectively\. \(Direct3D clip volume definition\)  
  
### perspectiveFovZO\(\) function  
#### <code>glm.<code>**perspectiveFovZO**(**fov**: *float*, **width**: *float*, **height**: *float*, **near**: *float*, **far**: *float*) -\> *fmat4x4*</code></code>  
&emsp;&emsp;See perspectiveFovRH\_ZO\.  
  
### perspectiveLH\(\) function  
#### <code>glm.<code>**perspectiveLH**(**fovy**: *float*, **aspect**: *float*, **near**: *float*, **far**: *float*) -\> *fmat4x4*</code></code>  
&emsp;&emsp;See perspectiveLH\_NO\.  
  
### perspectiveLH\_NO\(\) function  
#### <code>glm.<code>**perspectiveLH_NO**(**fovy**: *float*, **aspect**: *float*, **near**: *float*, **far**: *float*) -\> *fmat4x4*</code></code>  
&emsp;&emsp;Creates a matrix for a left handed, symetric perspective\-view frustum\. The near and far  
&emsp;&emsp;clip planes correspond to z normalized device coordinates of \-1 and \+1 respectively\.  
&emsp;&emsp;\(OpenGL clip volume definition\)  
  
### perspectiveLH\_ZO\(\) function  
#### <code>glm.<code>**perspectiveLH_ZO**(**fovy**: *float*, **aspect**: *float*, **near**: *float*, **far**: *float*) -\> *fmat4x4*</code></code>  
&emsp;&emsp;Creates a matrix for a left handed, symetric perspective\-view frustum\. The near and far  
&emsp;&emsp;clip planes correspond to z normalized device coordinates of 0 and \+1 respectively\.  
&emsp;&emsp;\(Direct3D clip volume definition\)  
  
### perspectiveNO\(\) function  
#### <code>glm.<code>**perspectiveNO**(**fovy**: *float*, **aspect**: *float*, **near**: *float*, **far**: *float*) -\> *fmat4x4*</code></code>  
&emsp;&emsp;See perspectiveRH\_NO\.  
  
### perspectiveRH\(\) function  
#### <code>glm.<code>**perspectiveRH**(**fovy**: *float*, **aspect**: *float*, **near**: *float*, **far**: *float*) -\> *fmat4x4*</code></code>  
&emsp;&emsp;See perspectiveRH\_NO\.  
  
### perspectiveRH\_NO\(\) function  
#### <code>glm.<code>**perspectiveRH_NO**(**fovy**: *float*, **aspect**: *float*, **near**: *float*, **far**: *float*) -\> *fmat4x4*</code></code>  
&emsp;&emsp;Creates a matrix for a right handed, symetric perspective\-view frustum\. The near and far  
&emsp;&emsp;clip planes correspond to z normalized device coordinates of \-1 and \+1 respectively\.  
&emsp;&emsp;\(OpenGL clip volume definition\)  
  
### perspectiveRH\_ZO\(\) function  
#### <code>glm.<code>**perspectiveRH_ZO**(**fovy**: *float*, **aspect**: *float*, **near**: *float*, **far**: *float*) -\> *fmat4x4*</code></code>  
&emsp;&emsp;Creates a matrix for a right handed, symetric perspective\-view frustum\. The near and far  
&emsp;&emsp;clip planes correspond to z normalized device coordinates of 0 and \+1 respectively\.  
&emsp;&emsp;\(Direct3D clip volume definition\)  
  
### perspectiveZO\(\) function  
#### <code>glm.<code>**perspectiveZO**(**fovy**: *float*, **aspect**: *float*, **near**: *float*, **far**: *float*) -\> *fmat4x4*</code></code>  
&emsp;&emsp;See perspectiveRH\_ZO\.  
  
### tweakedInfinitePerspective\(\) function  
#### <code>glm.<code>**tweakedInfinitePerspective**(**fovy**: *float*, **aspect**: *float*, **near**: *float*) -\> *fmat4x4*</code></code>  
&emsp;&emsp;Creates a matrix for a symmetric perspective\-view frustum with far plane at infinite for  
&emsp;&emsp;graphics hardware that doesn't support depth clamping\.  
  
#### <code>glm.<code>**tweakedInfinitePerspective**(**fovy**: *float*, **aspect**: *float*, **near**: *float*, **epsilon**: *float*) -\> *fmat4x4*</code></code>  
&emsp;&emsp;Creates a matrix for a symmetric perspective\-view frustum with far plane at infinite for  
&emsp;&emsp;graphics hardware that doesn't support depth clamping\.  
  
