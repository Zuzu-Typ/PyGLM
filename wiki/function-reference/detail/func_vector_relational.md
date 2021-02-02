[//]: # (generated using SlashBack 0.2.0)

  
# func\_vector\_relational methods  
The following methods are all part of the **func\_vector\_relational methods**\.  
Relational vector functions\.  
## Table of contents  
  
* [**all** function](#all-function)  
* [**any** function](#any-function)  
* [**equal** function](#equal-function)  
* [**greaterThan** function](#greaterthan-function)  
* [**greaterThanEqual** function](#greaterthanequal-function)  
* [**lessThan** function](#lessthan-function)  
* [**lessThanEqual** function](#lessthanequal-function)  
* [**notEqual** function](#notequal-function)  
* [**not\_** function](#not_-function)  
  
### all\(\) function  
#### <code>glm.<code>**all**(**v**: *bvecN*) -\> *bool*</code></code>  
&emsp;&emsp;Returns ``` True ``` if all components of ``` x ``` are ``` True ```\.  
  
### any\(\) function  
#### <code>glm.<code>**any**(**v**: *bvecN*) -\> *bool*</code></code>  
&emsp;&emsp;Returns ``` True ``` if any component of ``` x ``` is ``` True ```\.  
  
### equal\(\) function  
#### <code>glm.<code>**equal**(**x**: *vecN*, **y**: *vecN*) -\> *bvecN*</code></code>  
&emsp;&emsp;Returns the component\-wise comparison of result ``` x == y ```\.  
  
#### <code>glm.<code>**equal**(**x**: *quat*, **y**: *quat*) -\> *bvec4*</code></code>  
&emsp;&emsp;Returns the component\-wise comparison of result ``` x == y ```\.  
  
#### <code>glm.<code>**equal**(**x**: *matNxM*, **y**: *matNxM*) -\> *bvecN*</code></code>  
&emsp;&emsp;Perform a component\-wise equal\-to comparison of two matrices\. Return a boolean vector which  
&emsp;&emsp;components value is ``` True ``` if this expression is satisfied per column of the matrices\.  
  
#### <code>glm.<code>**equal**(**x**: *number*, **y**: *number*, **ULPs**: *int*) -\> *bool*</code></code>  
&emsp;&emsp;Returns the component\-wise comparison between two scalars in term of ``` ULPs ```\.  
  
#### <code>glm.<code>**equal**(**x**: *vecN*, **y**: *vecN*, **ULPs**: *int*) -\> *bvecN*</code></code>  
&emsp;&emsp;Returns the component\-wise comparison between two vectors in term of ``` ULPs ```\.  
  
#### <code>glm.<code>**equal**(**x**: *matNxM*, **y**: *matNxM*, **ULPs**: *int*) -\> *bvecN*</code></code>  
&emsp;&emsp;Returns the component\-wise comparison between two matrices in term of ``` ULPs ```\.  
  
#### <code>glm.<code>**equal**(**x**: *vecN*, **y**: *vecN*, **ULPs**: *ivecN*) -\> *bvecN*</code></code>  
&emsp;&emsp;Returns the component\-wise comparison between two vectors in term of ``` ULPs ```\.  
  
#### <code>glm.<code>**equal**(**x**: *matNxM*, **y**: *matNxM*, **ULPs**: *ivecN*) -\> *bvecN*</code></code>  
&emsp;&emsp;Returns the component\-wise comparison between two matrices in term of ``` ULPs ```\.  
  
#### <code>glm.<code>**equal**(**x**: *number*, **y**: *number*, **epsilon**: *number*) -\> *bool*</code></code>  
&emsp;&emsp;Returns the comparison of ``` |x - y| < epsilon ```\.  
  
#### <code>glm.<code>**equal**(**x**: *vecN*, **y**: *vecN*, **epsilon**: *number*) -\> *bvecN*</code></code>  
&emsp;&emsp;Returns the component\-wise comparison of ``` |x - y| < epsilon ```\.  
  
#### <code>glm.<code>**equal**(**x**: *quat*, **y**: *quat*, **epsilon**: *number*) -\> *bvec4*</code></code>  
&emsp;&emsp;Returns the component\-wise comparison of ``` |x - y| < epsilon ```\.  
  
#### <code>glm.<code>**equal**(**x**: *matNxM*, **y**: *matNxM*, **epsilon**: *number*) -\> *bvecN*</code></code>  
&emsp;&emsp;Returns the component\-wise comparison of ``` |x - y| < epsilon ```\.  
  
#### <code>glm.<code>**equal**(**x**: *vecN*, **y**: *vecN*, **epsilon**: *vecN*) -\> *bvecN*</code></code>  
&emsp;&emsp;Returns the component\-wise comparison of ``` |x - y| < epsilon ```\.  
  
#### <code>glm.<code>**equal**(**x**: *matNxM*, **y**: *matNxM*, **epsilon**: *vecN*) -\> *bvecN*</code></code>  
&emsp;&emsp;Returns the component\-wise comparison of ``` |x - y| < epsilon ```\.  
  
### greaterThan\(\) function  
#### <code>glm.<code>**greaterThan**(**x**: *vecN*, **y**: *vecN*) -\> *bvecN*</code></code>  
&emsp;&emsp;Returns the component\-wise comparison of result ``` x > y ```\.  
  
#### <code>glm.<code>**greaterThan**(**x**: *quat*, **y**: *quat*) -\> *bvec4*</code></code>  
&emsp;&emsp;Returns the component\-wise comparison of result ``` x > y ```\.  
  
### greaterThanEqual\(\) function  
#### <code>glm.<code>**greaterThanEqual**(**x**: *vecN*, **y**: *vecN*) -\> *bvecN*</code></code>  
&emsp;&emsp;Returns the component\-wise comparison of result ``` x >= y ```\.  
  
#### <code>glm.<code>**greaterThanEqual**(**x**: *quat*, **y**: *quat*) -\> *bvec4*</code></code>  
&emsp;&emsp;Returns the component\-wise comparison of result ``` x >= y ```\.  
  
### lessThan\(\) function  
#### <code>glm.<code>**lessThan**(**x**: *vecN*, **y**: *vecN*) -\> *bvecN*</code></code>  
&emsp;&emsp;Returns the component\-wise comparison of result ``` x < y ```\.  
  
#### <code>glm.<code>**lessThan**(**x**: *quat*, **y**: *quat*) -\> *bvec4*</code></code>  
&emsp;&emsp;Returns the component\-wise comparison of result ``` x < y ```\.  
  
### lessThanEqual\(\) function  
#### <code>glm.<code>**lessThanEqual**(**x**: *vecN*, **y**: *vecN*) -\> *bvecN*</code></code>  
&emsp;&emsp;Returns the component\-wise comparison of result ``` x <= y ```\.  
  
#### <code>glm.<code>**lessThanEqual**(**x**: *quat*, **y**: *quat*) -\> *bvec4*</code></code>  
&emsp;&emsp;Returns the component\-wise comparison of result ``` x <= y ```\.  
  
### notEqual\(\) function  
#### <code>glm.<code>**notEqual**(***args**) -\> *bvecN*</code></code>  
&emsp;&emsp;Returns ``` not equal(*args) ```\.  
  
### not\_\(\) function  
#### <code>glm.<code>**not_**(**v**: *bvecN*) -\> *bool*</code></code>  
&emsp;&emsp;Returns the component\-wise logical complement of ``` x ```\.  
  
