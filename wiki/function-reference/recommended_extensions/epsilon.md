[//]: # (generated using SlashBack 0.2.0)

  
# epsilon methods  
The following methods are all part of the **epsilon methods**\.  
Comparison functions for a user defined epsilon values\.  
## Table of contents  
  
* [**epsilonEqual** function](#epsilonequal-function)  
* [**epsilonNotEqual** function](#epsilonnotequal-function)  
  
### epsilonEqual\(\) function  
#### <code>glm.<code>**epsilonEqual**(**x**: *number*, **y**: *number*, **epsilon**: *number*) -\> *bool*</code></code>  
&emsp;&emsp;Returns the component\-wise comparison of ``` |x - y| < epsilon ```\.  
  
#### <code>glm.<code>**epsilonEqual**(**x**: *vecN*, **y**: *vecN*, **epsilon**: *number*) -\> *bvecN*</code></code>  
&emsp;&emsp;Returns the component\-wise comparison of ``` |x - y| < epsilon ```\.  
  
#### <code>glm.<code>**epsilonEqual**(**x**: *quat*, **y**: *quat*, **epsilon**: *number*) -\> *bvecN*</code></code>  
&emsp;&emsp;Returns the component\-wise comparison of ``` |x - y| < epsilon ```\.  
  
#### <code>glm.<code>**epsilonEqual**(**x**: *vecN*, **y**: *vecN*, **epsilon**: *vecN*) -\> *bvecN*</code></code>  
&emsp;&emsp;Returns the component\-wise comparison of ``` |x - y| < epsilon ```\.  
  
### epsilonNotEqual\(\) function  
#### <code>glm.<code>**epsilonNotEqual**(**x**: *number*, **y**: *number*, **epsilon**: *number*) -\> *bool*</code></code>  
&emsp;&emsp;Returns the component\-wise comparison of ``` |x - y| >= epsilon ```\.  
  
#### <code>glm.<code>**epsilonNotEqual**(**x**: *vecN*, **y**: *vecN*, **epsilon**: *number*) -\> *bvecN*</code></code>  
&emsp;&emsp;Returns the component\-wise comparison of ``` |x - y| >= epsilon ```\.  
  
#### <code>glm.<code>**epsilonNotEqual**(**x**: *quat*, **y**: *quat*, **epsilon**: *number*) -\> *bvecN*</code></code>  
&emsp;&emsp;Returns the component\-wise comparison of ``` |x - y| >= epsilon ```\.  
  
#### <code>glm.<code>**epsilonNotEqual**(**x**: *vecN*, **y**: *vecN*, **epsilon**: *vecN*) -\> *bvecN*</code></code>  
&emsp;&emsp;Returns the component\-wise comparison of ``` |x - y| >= epsilon ```\.  
  
