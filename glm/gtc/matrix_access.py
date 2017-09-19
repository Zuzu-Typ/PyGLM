import numpy
def row(m, index, x=None):
    if not x:
        assert(index >= 0 and index < m[0].length())
        return m.row_type(numpy.array(m.value[:,index]).reshape(4))
    assert(index >= 0 and index < m[0].length())
    
    Result = m.__class__(m.value.T)
    Result[index] = x
    return m.__class__(Result.value.T)
    

def column(m, index, x=None):
    if not x:
        assert(index >= 0 and index < m.length())

        return m[index]
    assert(index >= 0 and index < m.length())

    Result = m.__class__(m)
    Result[index] = x
    return Result
