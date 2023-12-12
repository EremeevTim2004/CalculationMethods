#include <iostream>
#include <vector>
using namespace std;
/*

-1 0 1 2
-1 0 1 8

*/
void print(vector<vector<float>>& matrix) {
	for (int i = 0; i < matrix.size(); cout << "\n", ++i)
		for (int j = 0; j < matrix[i].size(); ++j)
			cout << matrix[i][j] << "  ";
}

int main() {
	setlocale(LC_ALL, "rus");

	int n = 0; cout << "степень многочлена : "; cin >> n;

	vector<float> X_n(n + 1); cout << "X_n: ";
	for (int i = 0; i < n + 1; cin >> X_n[i], ++i);

	vector<float> f_n(n + 1); cout << "f_n: ";
	for (int i = 0; i < n + 1; cin >> f_n[i], ++i);

	vector<vector<float>> matrix(4 * n);
	for (int i = 0; i < 4 * n; matrix[i].resize(4 * n + 1), ++i);
	for (int i = 0; i < 4 * n; ++i)
		if (i < 2 * n)
			if (i < n)
				matrix[i][4 * n] = f_n[i];
			else
				matrix[i][4 * n] = f_n[i - n + 1];
		else
			matrix[i][4 * n] = 0;

	float k = 0;
	bool flag = true;
	float h = 1;
	for (int i = 0; i < 4 * n; ++i) {
		for (int j = 0; j < 4 * n; ++j) {
			if (i < n && i == j) {
				matrix[i][j] = 1;
				break;
			}
			else if (i >= n && i < 2 * n && (j % n == 0)) {
				matrix[i][j + (i % n)] = 1 * pow(h, j / n);

			}
			else if (i >= 2 * n && i < 2 * n + (n - 1) && j >= n && (j % n == 0)) {
				if (flag) {
					matrix[i][j + (i % n) + 1] = -1;
				}
				flag = false;
				matrix[i][j + (i % n)] = (j / n) * pow(h, j / n - 1);

			}
			else if (i == 3 * n + 1 && j == 2 * n) {
				matrix[i][j] = 2;

			}
			else if (i == 2 * n + (n - 1) && j == 2 * n) {

				matrix[i][j] = 2;
				matrix[i][j + 1] = -2;
				matrix[i][j + n] = 6 * h;
			}
			else if (i == 3 * n && j == 2 * n + 1) {

				matrix[i][j] = 2;
				matrix[i][j + 1] = -2;
				matrix[i][j + n] = 6 * h;
				matrix[i + 2][j + 1] = 2;
				matrix[i + 2][j + n + 1] = 6 * h;
			}
		}
	}
	vector <string> unknown{ "a1", "a2", "a3", "b1", "b2", "b3"
							, "c1", "c2", "c3", "d1", "d2", "d3", "f"
	};
	for (int i = 0; i < unknown.size(); cout << unknown[i] << " ", ++i) {}


	cout << endl;
	print(matrix);
	return 0;
}