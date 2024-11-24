from pyglm.glm import *
from pyglm import glm_typing, typing, __version__

import warnings as __warnings

__warnings.warn("Importing PyGLM via \"import glm\" is going to be deprecated in the future.\nUse \"from pyglm import glm\" instead", PendingDeprecationWarning)