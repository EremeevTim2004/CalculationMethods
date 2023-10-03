import numpy as np

def polynom(x, f, a):
    Px = 0
    for i in range(len(f)):
        Px += (x ** i) * a[i]
    return Px

x = np.array([[16., -8., 4., -2., 1.]
            , [1., -1., 1., -1., 1.]
            , [0., 0., 0., 0., 1.]
            , [1., 1., 1., 1., 1.]
            , [16., 8., 4., 2., 1.]])
f = np.array([-8., -1., 0., 1., 8.])
a = np.linalg.solve(x, f)
print("a_k =", a)

x0 = np.array([0., 0.5, 1., 1.5, 2.])
for i in range(len(x0)):
    Px = polynom(x0[i], f, a)
    print("P(" + str(x0[i]) + ") = " + str(Px))