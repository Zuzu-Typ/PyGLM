def lessThan(x, y):
    assert (len(x) == len(y))

    Result = x.__class__()

    for i in range(len(Result)):
        Result[i] = x[i] < y[i]

    return Result

def lessThanEqual(x, y):
    assert (len(x) == len(y))

    Result = x.__class__()

    for i in range(len(Result)):
        Result[i] = x[i] <= y[i]

    return Result

def greaterThan(x, y):
    assert (len(x) == len(y))

    Result = x.__class__()

    for i in range(len(Result)):
        Result[i] = x[i] > y[i]

    return Result

def greaterThanEqual(x, y):
    assert (len(x) == len(y))

    Result = x.__class__()

    for i in range(len(Result)):
        Result[i] = x[i] >= y[i]

    return Result

def equal(x, y):
    assert (len(x) == len(y))

    Result = x.__class__()

    for i in range(len(Result)):
        Result[i] = x[i] == y[i]

    return Result

def notEqual(x, y):
    assert (len(x) == len(y))

    Result = x.__class__()

    for i in range(len(Result)):
        Result[i] = x[i] != y[i]

    return Result

def not_(v):
    Result = v.__class__()

    for i in range(len(Result)):
        Result[i] = not v[i]

    return Result

