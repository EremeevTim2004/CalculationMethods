#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	int n;
	cin >> n;
	int* inputx = new int[n + 1];
	for (int i = 0; i <= n; i++) {
		cin >> inputx[i];
	}
	int* inputf = new int[n + 1];
	for (int i = 0; i <= n; i++) {
		cin >> inputf[i];
	}
	cout << endl;
	int** m = new int* [n + 1];
	for (int i = 0; i <= n; i++) {
		m[i] = new int[n + 2];
	}
	for (int i = 0; i < n+1; i++) {
		for (int j = 0; j < n+2; j++) {
			if (j != n + 1) {
				m[i][j] = pow(inputx[i], n - j);
			}
			else {
				m[i][j] = inputf[i];
			}
		}
	}
	for (int i = 0; i < n + 1; i++) {
		for (int j = 0; j < n + 2; j++) {
			cout << setw(6) << m[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}