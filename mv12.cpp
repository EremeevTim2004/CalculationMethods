#include <iostream>
#include <iomanip>

using namespace std;

double* solveGauss(int n, double** a, double* b) {
	double* x = new double[n];
	for (int i = 0; i < n; i++) {
		x[i] = 0;
	}
	double temp;
	double s = 0;
	double** ext = new double* [n];
	for (int i = 0; i < n; i++) {
		ext[i] = new double[n + 1];
	}
	//======MAKE MASSIVE EXT
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n + 1; j++) {
			ext[i][j] = j == n ? b[i] : a[i][j];
		}
	}
	double mx;
	int index;
	//======SOLVE start
	for (int k = 0; k < n; k++) {
		if (ext[k][k] == 0) {
			mx = abs(ext[k][k]);
			index = k;
			for (int i = k + 1; i < n; i++) {
				if (abs(ext[i][k]) > mx) {
					mx = abs(ext[i][k]);
					index = i;
				}
			}
			if (index == k) {
				cout << "GAUSS: NOT FOUND ELEMENT IN MAT TO REPLACE" << endl;
				return x;
			}
			swap(ext[index], ext[k]);
		}
		for (int i = k; i < n; i++) {
			if (i == k) {
				temp = ext[i][i];
				for (int j = 0; j < n + 1; j++) {
					ext[i][j] /= temp;
				}
			}
			else {
				temp = ext[i][k];
				for (int j = 0; j < n + 1; j++) {
					ext[i][j] -= ext[k][j] * temp;
				}
			}
		}
	}
	//======SOLVE end
	//======MAKE MASSIVE X
	for (int i = n - 1; i > -1; i--) {
		s = 0;
		for (int j = 0; j < n; j++) {
			s += ext[i][j] * x[j];
		}
		x[i] += ext[i][n] - s;
	}

	return x;
}

double p(double x) {
	return x * x;
}

double q(double x) {
	return x;
}

int main() {
	int n;
	int v = 1;
	int t = v;
	cout << "Type n: ";
	cin >> n;
	double h = t * 1.0 / (n + 1);
	double* x = new double[n];
	for (int i = 0; i < n; i++) {
		x[i] = h + h * i;
		cout << x[i] << " ";
	}
	cout << endl;
	double* fi = new double[n];
	for (int i = 0; i < n; i++) {
		fi[i] = pow(x[i], i+1) * (x[i] - t);
		cout << "fi[" << i << "] = " << fi[i] << endl;
	}
	double** a = new double* [n];
	for (int i = 0; i < n; i++) {
		a[i] = new double[n];
	}
	cout << endl;
	cout << "Type MatElems: ";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			a[i][j] = 0;
		}
	}

	cout << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << setw(12) << a[i][j] << " ";
		}
		cout << endl;
	}
	
	double* solved = solveGauss(n, a, fi);
	cout << "=================RESULT===================" << endl;
	cout << "Nodes (x)  : ";
	for (int i = 0; i < n + 1; i++) {
		cout << setw(12) << x[i] << " ";
	}
	cout << endl;
	cout << "yMeth (y)  : ";
	for (int i = 0; i < n + 1; i++) {
		if (i != 0 && i != n) {
			cout << setw(12) << solved[i - 1] << " ";
		}
		else cout << setw(12) << 0 << " ";
	}
	cout << endl;
	cout << "yTochn (yt): ";
	for (int i = 0; i < n + 1; i++) {
		cout << setw(12) << v * x[i] * x[i] * (x[i] - t) << " ";
	}
	cout << endl;
	cout << "e (yT - y) : ";
	for (int i = 0; i < n + 1; i++) {
		if (i != 0 && i != n) {
			cout << setw(12) << abs(v * x[i] * x[i] * (x[i] - t) - solved[i - 1]) << " ";
		}
		else cout << setw(12) << abs(v * x[i] * x[i] * (x[i] - t) - 0) << " ";
	}
}