#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	int n;

	cin >> n;
	double* inputx = new double[n + 1];
	double* inputxMid = new double[n];
	double* inputf = new double[n + 1];
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
	
	for (int m = 0; m < n; m++) {
		double sum = 0;
		double x = inputxMid[m];
		for (int i = 0; i <= n; i++) {
			double chisl = 1;
			for (int j = 0; j <= n; j++) {
				if (j == i) continue;
				else chisl *= x - inputx[j];
			}
			double znam = 1;
			for (int j = 0; j <= n; j++) {
				if (j == i) continue;
				else znam *= inputx[i] - inputx[j];
			}
			sum += inputf[i] * chisl / znam;
		}
		outf[m] = sum;
	}

	for (int i = 0; i < n + 1; i++) {
		cout << "x = " << inputx[i] << " y = " << inputf[i] << endl;
	}

	for (int i = 0; i < n; i++) {
		cout << "xD = " << inputxMid[i] << " yD = " << outf[i] << endl;
	}

	return 0;
}