#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

double** createMat(int n, int v) {
	double** mat = new double*[n];
	for (int i = 0; i < n; i++) {
		mat[i] = new double[n];
	}

	for (int i = 0; i < n; i++) {
		mat[i][i] = v;
		for (int j = 0; j < n; j++) {
			if (i != j) {
				mat[i][j] = v * 0.01;
			}
		}
		v++;
	}
	return mat;
}

double* matMultVec(double** mat, double* vec, int n) {
	double* newV = new double[n];
	for (int i = 0; i < n; i++) {
		newV[i] = 0;
		for (int j = 0; j < n; j++) {
			newV[i] += mat[i][j] * vec[j];
		}
	}
	return newV;
}

double** convAlpha(double** mat, int n) {
	double** a = new double* [n];
	for (int i = 0; i < n; i++) {
		a[i] = new double[n];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) {
				a[i][j] = 0;
			}
			else {
				a[i][j] = -mat[i][j] / mat[i][i];
			}
		}
	}
	return a;
}

double* convBeta(double* vec, double** mat, int n) {
	double* beta = new double [n];
	for (int i = 0; i < n; i++) {
		beta[i] = vec[i] / mat[i][i];
	}
	return beta;
}

double* vecSum(double* a, double* b, int n) {
	double* res = new double [n];
	for (int i = 0; i < n; i++) {
		res[i] = a[i] + b[i];
	}
	return res;
}

double* vecDif(double* a, double* b, int n) {
	double* res = new double [n];
	for (int i = 0; i < n; i++) {
		res[i] = a[i] - b[i];
	}
	return res;
}

double norm(double* v, int n) {
	double mx = v[0];
	for (int i = 0; i < n; i++) {
		if (mx < v[i]) {
			mx = v[i];
		}
	}
	return mx;
}

void printMat(double** mat, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << setw(12) << mat[i][j] << " ";
		}
		cout << endl;
	}
}

int main() {
	int n; int v;
	cin >> n >> v;
	double** mat = createMat(n, v);
	double* x = new double [n];
	for (int i = 0; i < n; i++) {
		mat[i][i] = v;
		x[i] = v;
		v++;
	}

	double* x0 = new double [n];
	for (int i = 0; i < n; i++) {
		x0[i] = 0;
	}
	double eps = 0.0001;
	double* b = matMultVec(mat, x, n);
	double** alpha = new double* [n];
	for (int i = 0; i < n; i++) {
		alpha[i] = new double[n];
	}
	alpha = convAlpha(mat, n);
	double* beta = convBeta(b, mat, n);
	double* x1 = new double [n];
	double* x2 = new double [n];
	//===================PRINTING=====================
	for (int i = 0; i < n; i++) {
		cout << beta[i] << " ";
	}
	cout << endl;
	cout << "x0: "; 
	for (int i = 0; i < n; i++) {
		cout << x0[i] << " ";
	}
	cout << endl;
	x1 = vecSum(matMultVec(alpha, x0, n), beta, n);
	cout << "x1: ";  
	for (int i = 0; i < n; i++) {
		cout << x1[i] << " ";
	}
	cout << endl;
	x2 = vecSum(matMultVec(alpha, x1, n), beta, n);
	cout << "x2: "; 
	for (int i = 0; i < n; i++) {
		cout << x2[i] << " ";
	}
	cout << endl;
	int i = 3;
	//===================SOLVE===========================
	while (abs(norm(vecDif(x2, x1, n), n)) > eps) {
		x1 = vecSum(matMultVec(alpha, x2, n), beta, n);
		cout << "x" << i << ": "; 
		for (int i = 0; i < n; i++) {
			cout << x1[i] << " ";
		}
		cout << endl;
		i++;
		x2 = vecSum(matMultVec(alpha, x1, n), beta, n);
		cout << "x" << i << ": ";
		for (int i = 0; i < n; i++) {
			cout << x2[i] << " ";
		}
		cout << endl;
		i++;
	}
}