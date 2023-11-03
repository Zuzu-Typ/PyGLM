import glm
from glm import min as glm_min

a = glm.array([glm.vec2(x, x + 1) for x in range(0, 10000, 2)])
a_x, a_y = a.split_components()

for i in range(99999):
    # PyGLM
    glm_min(a_x)
    glm_min(a_y)

    # Python
    # min(a_x)
    # min(a_y)