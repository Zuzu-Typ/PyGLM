class PyGLMError(Exception):
    pass

def _error(msg):
    raise PyGLMError(msg)
