[//]: # (generated using SlashBack 0.2.0)

  
# matrix\_projection methods  
The following methods are all part of the **matrix\_projection methods**\.  
Functions that generate common projection transformation matrices\.  
## Table of contents  
  
* [**pickMatrix** function](#pickmatrix-function)  
* [**project** function](#project-function)  
* [**projectNO** function](#projectno-function)  
* [**projectZO** function](#projectzo-function)  
* [**unProject** function](#unproject-function)  
* [**unProjectNO** function](#unprojectno-function)  
* [**unProjectZO** function](#unprojectzo-function)  
  
### pickMatrix\(\) function  
#### <code>glm.<code>**pickMatrix**(**center**: *vec2*, **delta**: *vec2*, **viewport**: *vec4*) -\> *mat4*</code></code>  
&emsp;&emsp;Define a picking region\.  
  
### project\(\) function  
#### <code>glm.<code>**project**(**obj**: *vec3*, **model**: *mat4*, **proj**: *mat4*, **viewport**: *vec4*) -\> *vec3*</code></code>  
&emsp;&emsp;See projectNO\(\)\.  
  
### projectNO\(\) function  
#### <code>glm.<code>**projectNO**(**obj**: *vec3*, **model**: *mat4*, **proj**: *mat4*, **viewport**: *vec4*) -\> *vec3*</code></code>  
&emsp;&emsp;Map the specified object coordinates \(obj\.x, obj\.y, obj\.z\) into window coordinates\.  
&emsp;&emsp;The near and far clip planes correspond to z normalized device coordinates of \-1 and \+1  
&emsp;&emsp;respectively\. \(OpenGL clip volume definition\)  
  
### projectZO\(\) function  
#### <code>glm.<code>**projectZO**(**obj**: *vec3*, **model**: *mat4*, **proj**: *mat4*, **viewport**: *vec4*) -\> *vec3*</code></code>  
&emsp;&emsp;Map the specified object coordinates \(obj\.x, obj\.y, obj\.z\) into window coordinates\.  
&emsp;&emsp;The nearand far clip planes correspond to z normalized device coordinates of 0 and \+1  
&emsp;&emsp;respectively\. \(Direct3D clip volume definition\)  
  
### unProject\(\) function  
#### <code>glm.<code>**unProject**(**win**: *vec3*, **model**: *mat4*, **proj**: *mat4*, **viewport**: *vec4*) -\> *vec3*</code></code>  
&emsp;&emsp;See unProjectNO\(\)\.  
  
### unProjectNO\(\) function  
#### <code>glm.<code>**unProjectNO**(**win**: *vec3*, **model**: *mat4*, **proj**: *mat4*, **viewport**: *vec4*) -\> *vec3*</code></code>  
&emsp;&emsp;Map the specified window coordinates \(win\.x, win\.y, win\.z\) into object coordinates\.  
&emsp;&emsp;The nearand far clip planes correspond to z normalized device coordinates of \-1 and \+1  
&emsp;&emsp;respectively\. \(OpenGL clip volume definition\)  
  
### unProjectZO\(\) function  
#### <code>glm.<code>**unProjectZO**(**win**: *vec3*, **model**: *mat4*, **proj**: *mat4*, **viewport**: *vec4*) -\> *vec3*</code></code>  
&emsp;&emsp;Map the specified window coordinates \(win\.x, win\.y, win\.z\) into object coordinates\.  
&emsp;&emsp;The nearand far clip planes correspond to z normalized device coordinates of 0 and \+1  
&emsp;&emsp;respectively\. \(Direct3D clip volume definition\)  
  
