import numpy as np

def lagrange (x, f, x0):
	res = 0.0
	for i in range(len(f)):
		l = f[i] 
		for j in range(len(x)): 
			if i != j: l *= (x0 - x[j]) / (x[i] - f[j])
		res += l
	return res

x_in = np.array([-2, -1, 0, 2])

f_in = np.array([-8, -1, 0, 8])

x_table = np.array([-2, -1.5, -1, -0.5, 0, 0.5, 1, 1.5, 2])

for i in range(len(x_table)):
	res = lagrange(x_in, f_in, x_table[i])
	print("L(" + str(x_table[i]) + ") = " + str(res))