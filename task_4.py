import numpy as np

x_in = np.array([-2, -1, 0, 1, 2])
f_in = np.array([-8, -1, 0, 1, 8])

x_tch = np.array([-2, -1.5, -1, -0.5, 0, 0.5, 1, 1.5, 2])

def getRazn(x, y):
    rRazn = [[0] * len(x) for _ in range(len(x))]
    for i in range(len(x)): rRazn[i][0] = y[i]

    for i in range(1, len(x)): 
        for j in range(i, len(x)):
            rRazn[j][i] = (rRazn[j][i - 1] - rRazn[j - 1][i - 1]) / (x[j] - x[j - i])
    return rRazn

def newton(x_true, y_true, x0):
    rRazn = getRazn(x_true, y_true)

    lstR = []
    for i in range(len(rRazn)): lstR.append(rRazn[i][i])

    result = lstR[0]
    for i in range(1, len(lstR)):
        p = lstR[i]
        for j in range(i): p *= (x0 - x_in[j]);
        result += p
    return result

rr = getRazn(x_in, f_in)
print('Table:')
rnp = np.array([rr[0], rr[1], rr[2], rr[3], rr[4]])
print(rnp)
print()

for x in x_tch:
    res = newton(x_in, f_in, x)
    print("N("+ str(x) +") = " + str(res))