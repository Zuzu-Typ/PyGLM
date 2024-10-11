
import os, shutil

os.environ["TEST_PICKLING"] = "True"

TEST = True

TEST_PERFORMANCE = False

GEN_DOC = True

if TEST_PERFORMANCE:
    import PyGLM_vs_NumPy

if TEST:
    import PyGLM_test, time, traceback, sys
    shutil.copy2("PyGLM_test.py", "../test/PyGLM_test.py")
    print("Testing PyGLM...")
    start_time = time.time()
    for member in dir(PyGLM_test):
        if member.startswith("test"):
            try:
                getattr(PyGLM_test, member)()
            except:
                print("The following test failed: " + member, file=sys.stderr)
                traceback.print_exc()
    print("Finished tests in {:.3g}s".format(time.time()-start_time))


import glm
from glm import *

if GEN_DOC:
    import generate_function_reference

if True:
    import time
    def t(func, *args, r=1000000, **kw):
        start = time.time()
        for i in range(r):
            func(*args, **kw)
        return time.time() - start
    from sys import getrefcount as rc
    def memcor(func, *args, r=1000000, **kw):
        for i in range(r):
            try:
                func(*args, **kw)
            except:
                pass


