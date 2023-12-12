#include <iostream>
#include <iomanip>

using namespace std;

double* matMultVec(double** mat, double* vec, int n) {
	double* newVec = new double[n];
	for (int i = 0; i < n; i++) {
		newVec[i] = 0;
		for (int j = 0; j < n; j++) {
			newVec[i] += mat[i][j] * vec[j];
		}
	}
	return newVec;
}

int main() {
	int n = 5;
	double v = 6;
	double** a = new double* [n];
	for (int i = 0; i < n; i++) {
		a[i] = new double[n];
	}
	double* d = new double[n];
	double* x = new double[n];
	for (int i = 0; i < n; i++) {
		x[i] = v + i;
	}
	//======MAKE MASSIVE A
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (j < i + 2 && j > i - 2) {
				a[i][j] = i == j ? -(v + i) : (v + i * 1.0) / 100.0;
			}
			else a[i][j] = 0;
		}
	}
	//======MAKE MASSIVE B
	d = matMultVec(a, x, n);
	//======OUTPUT start
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << setw(6) << a[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

	double* p = new double[n];
	double* q = new double[n];
	// прямой ход
	p[0] = a[0][1] / -a[0][0]; // формула 10
	q[0] = d[0] / a[0][0]; // формула 11
	double bi; double ai; double ci;
	for (int i = 1; i < n - 1; i++) {
		bi = -1.0 * a[i][i];
		ai = a[i][i - 1];
		ci = a[i][i + 1];
		p[i] = ci / (bi - ai * p[i - 1]);
		q[i] = (ai * q[i - 1] - d[i]) / (bi - ai * p[i - 1]);
	}
	p[n - 1] = 0;
	q[n - 1] = (a[n - 1][n - 2] * q[n - 2] - d[n - 1]) / (-a[n - 1][n - 1] - a[n - 1][n - 2] * p[n - 2]);
	double* res = new double[n];
	// обратный ход
	res[n - 1] = q[n - 1];
	for (int i = n - 2; i >= 0; i--) {
		res[i] = p[i] * res[i + 1] + q[i];
	}

	for (int i = 0; i < n; i++) {
		cout << res[i] << " ";
	}
	cout << endl;

	return 0;
}