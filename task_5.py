import numpy as np

x = np.array([-1, 0, 1, 2])
f = np.array([-1, 0, 1, 8])

def optKoef(x, i):
    h = x[i] - x[i-1]
    arr = np.zeros((4, 4))
    arr[0][0] = arr[1][0] = arr[2][1] = 1
    arr[3][2] = 2
    arr[1][1] = h
    arr[1][2] = h*h
    arr[1][3] = h*h*h
    arr[2][2] = 2*h
    arr[2][3] = 3*h*h
    arr[3][3] = 6*h
    return arr

def koef(x):
    N = 4 * (len(x) - 1)
    arr = np.zeros((N, N))
    ones = np.zeros((4, 4))
    ones[2][1] = -1
    ones[3][2] = -2
    for i in range(int(N / 4) - 1):
        for j in range(int(N / 4)):
            if j < i:
                continue
            opt = optKoef(x, i+1)
            for k in range(4):
                for m in range(4):
                    arr[4 * i + k][4 * j + m] = opt[k][m]
            j += 1
            if j < int(N / 4):
                for k in range(4):
                    for m in range(4):
                        arr[4 * i + k][4 * j + m] = ones[k][m]
            break
    n = N - 1
    arr[n - 1][2] = 2
    hn = x[len(x) - 1] - x[len(x) - 2]
    arr[n - 3][n - 3] = 1
    arr[n - 2][n - 3] = 1
    arr[n - 2][n - 2] = hn
    arr[n - 2][n - 1] = hn * hn
    arr[n - 2][n] = hn * hn * hn
    arr[n][n - 1] = 2
    arr[n][n] = 6 * hn
    return arr


def result(f):
    N = 4 * (len(f) - 1)
    res = np.zeros((N, 1))
    for i in range(int(N / 4)):
        res[4*i] = f[i]
        res[4*i+1] = f[i+1]
    return res

def solveSys(x, f):
    X = np.linalg.solve(x,f)
    return X

def cubeSpline(X, a, b, c, d):
    def cS(x):
        dif = x - X
        return a + b * dif + c * dif * dif + d * dif * dif * dif
    return cS

print('Koef(x)')
arr = koef(x)
print(arr)
print()

print("Result")
res = result(f)
print(res)
print()

print('Solved system')
cube = solveSys(arr, res)
print(cube)
