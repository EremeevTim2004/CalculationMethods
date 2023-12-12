#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	int n = 5;
	double temp;
	double s = 0;
	double v = 6;
	double** a = new double* [n];
	for (int i = 0; i < n; i++) {
		a[i] = new double[n];
	}
	double* b = new double[n];
	double* x = new double[n];
	for (int i = 0; i < n; i++) {
		x[i] = 0;
	}
	double** ext = new double* [n];
	for (int i = 0; i < n; i++) {
		ext[i] = new double[n+1];
	}
	//======MAKE MASSIVE A
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			a[i][j] = i == j ? v + i : (v + i*1.0) / 100.0;
		}
	}
	//======MAKE MASSIVE B
	for (int i = 0; i < n; i++) {
		s = 0;
		for (int j = 0; j < n; j++) {
			s += a[i][j]*(v+j);
		}
		b[i] = s;
	}
	//======OUTPUT start
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << setw(6) << a[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

	for (int i = 0; i < n; i++) {
		cout << setw(6) << b[i];
	}
	cout << endl;
	//======OUTPUT end
	//======MAKE MASSIVE EXT
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n+1; j++) {
			ext[i][j] = j==n?b[i]:a[i][j];
		}
	}
	//======OUTPUT start
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n+1; j++) {
			cout << setw(6) << ext[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	//======OUTPUT end
	double mx;
	int index;
	//======SOLVE start
	for (int k = 0; k < n; k++) {
		if (ext[k][k] == 0) {
			mx = abs(ext[k][k]);
			index = k;
			for (int i = k+1; i < n; i++) {
				if (abs(ext[i][k]) > mx) {
					mx = abs(ext[i][k]);
					index = i;
				}
			}
			if (index == k) {
				cout << "GAUSS: NOT FOUND ELEMENT IN MAT TO REPLACE" << endl;
				return -1;
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
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n + 1; j++) {
				cout << setw(15) << ext[i][j] << " ";
			}
			cout << endl;
		}
		cout << "===========================ITERATION" << endl;
	}
	//======SOLVE end
	//======MAKE MASSIVE X
	for (int i = n-1; i > -1; i--) {
		s = 0;
		for (int j = 0; j < n; j++) {
			s += ext[i][j] * x[j];
		}
		x[i] = ext[i][n] - s;
	}

	for (int i = 0; i < n; i++) {
		cout << x[i] << " ";
	}
	cout << endl;

	return 0;
}