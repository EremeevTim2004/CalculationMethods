#include <iostream>
#include <iomanip>

using namespace std;

double* solveGauss(int n, double** a, double* x, double* b) {
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

double findOpred(int n, double** ext) {
	int switchCount = 1;
	double opredelitel = 1.0;
	double temp;
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
				return -1337;
			}
			swap(ext[index], ext[k]);
			switchCount *= -1;
		}
		for (int i = k; i < n; i++) {
			if (i == k) {
				temp = ext[i][i];
				opredelitel *= temp;
				for (int j = 0; j < n; j++) {
					ext[i][j] /= temp;
				}
			}
			else {
				temp = ext[i][k];
				for (int j = 0; j < n; j++) {
					ext[i][j] -= ext[k][j] * temp;
				}
			}
		}
	}
	//======SOLVE end
	return opredelitel * switchCount;
}

int main() {
	int n;
	cout << "Type n: ";
	cin >> n;
	cout << "Type MatElems: ";
	double** a = new double* [n];
	for (int i = 0; i < n; i++) {
		a[i] = new double[n];
	}
	double** resFin = new double* [n];
	for (int i = 0; i < n; i++) {
		resFin[i] = new double[n];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	for (int k = 0; k < n; k++) {
		double* b = new double[n];
		for (int j = 0; j < n; j++) {
			if (j == k) {
				b[j] = 1;
			}
			else b[j] = 0;
		}
		double* x = new double[n];
		for (int j = 0; j < n; j++) {
			x[j] = (a[j][k] != 0) ? 1.0 / a[j][k] : 0;
		}
		double* res = solveGauss(n, a, x, b);
		for (int j = 0; j < n; j++) {
			resFin[j][k] = res[j];
		}
	}
	cout << "A^(-1) START: ============" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << resFin[i][j] << " ";
		}
		cout << endl;
	}
	cout << "A^(-1) END: ============" << endl;
	cout << "OPREDELITEL: " << findOpred(n, a) << endl;
	return 0;
}