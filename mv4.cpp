#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	int n;
	cin >> n;
	double* inputx = new double[n + 1];
	double* inputf = new double[n + 1];
	double* inputxMid = new double[n];
	double* outf = new double[n];

	for (int i = 0; i <= n; i++) {
		cin >> inputx[i];
	}
	
	for (int i = 0; i <= n; i++) {
		cin >> inputf[i];
	}

	for (int i = 0; i < n; i++) {
		cin >> inputxMid[i];
	}
	cout << endl;
	//===============================
	double** m = new double* [n + 1];
	for (int i = 0; i <= n; i++) {
		m[i] = new double[n + 1];
	}
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			m[i][j] = 0;
		}
	}
	int ntemp = n;
	for (int j = 0; j <= n; j++) {
		for (int i = 0; i <= n - j; i++) {
			if (j == 0) {
				m[i][j] = inputf[i];
			}
			else {
				m[i][j] = (m[i + 1][j - 1] - m[i][j - 1]) / (inputx[j + i] - inputx[i]);
			}
		}
	}

	for (int k = 0; k < n; k++) {
		double sum = 0;
		double x = inputxMid[k];
		sum += inputf[0];
		for (int i = 1; i <= n; i++) {
			double mult = 1;
			for (int j = 0; j <= i; j++) {
				if (j == i) continue;
				else mult *= x - inputx[j];
			}
			sum += m[0][i] * mult;
		}
		outf[k] = sum;
	}

	for (int i = 0; i < n + 1; i++) {
		cout << "x = " << inputx[i] << " y = " << inputf[i] << endl;
	}

	for (int i = 0; i < n; i++) {
		cout << "xD = " << inputxMid[i] << " yD = " << outf[i] << endl;
	}

	return 0;
}