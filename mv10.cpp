#include <iostream>
#include <vector>

using namespace std;

void Iteration(int n, int V, double* x_n, double* yMet, double* yTochn, double* e_n) {
	
}

int main() {
	setlocale(LC_ALL, "rus");
	double h;
	int V, n;
	cout << "h: "; cin >> h;
	cout << "V: "; cin >> V;
	cout << "n: "; cin >> n;
	double* x_n = new double[n];
	double* yMet = new double[n];
	double* yTochn = new double[n];
	double* e_n = new double[n];

	cout << "\n=====================����� ������====================\n";
	x_n[0] = 1;
	for (int i = 1; i < n; i++)
		x_n[i] = x_n[i - 1] + h;
	cout << "\n";
	cout << "����: ";
	for (int i = 0; i < n; i++) cout << x_n[i] << " ";
	cout << endl;
	yMet[0] = V;

	for (int i = 1; i < n; i++)
		yMet[i] = yMet[i - 1] + h * (2 * V * x_n[i - 1] + V * pow(x_n[i - 1], 2) - yMet[i - 1]);
	cout << "������� ��������� �������� �������: \n";
	for (int i = 0; i < n; i++) cout << yMet[i] << " ";
	cout << endl;
	

	for (int i = 0; i < n; i++)
		yTochn[i] = V * pow(x_n[i], 2);

	cout << "������ �������: \n";
	for (int i = 0; i < n; i++) cout << yTochn[i] << " ";
	cout << endl;
	

	for (int i = 0; i < n; i++)
		e_n[i] = yMet[i] - yTochn[i];
	cout << "����������� � �����: \n";
	for (int i = 0; i < n; i++) cout << e_n[i] << " ";
	cout << endl;
	

	cout << "\n====================����. �. ������=========================\n";
	x_n[0] = 1;
	for (int i = 1; i < n; i++)
		x_n[i] = x_n[i - 1] + h;
	cout << "\n";
	
	cout << "����: ";
	for (int i = 0; i < n; i++) cout << x_n[i] << " ";
	cout << endl;

	yMet[0] = V;
	float yk = 0;
	for (int i = 1; i < n; i++) {
		yk = yMet[i - 1] + h * 0.5 * (2 * V * x_n[i - 1] + V * pow(x_n[i - 1], 2));
		yMet[i] = yMet[i - 1] + h * (2 * V * (x_n[i - 1] + h * 0.5) + V * pow((x_n[i - 1] + h * 0.5), 2) - yk);
	}

	cout << "������� ��������� �������� ������� (����. �. ������)\n";
	for (int i = 0; i < n; i++) cout << yMet[i] << " ";
	cout << endl;

	for (int i = 0; i < n; i++)
		yTochn[i] = V * pow(x_n[i], 2);
	cout << "������ �������: \n";
	for (int i = 0; i < n; i++) cout << yTochn[i] << " ";
	cout << endl;

	for (int i = 0; i < n; i++)
		e_n[i] = yMet[i] - yTochn[i];
	cout << "����������� � �����: \n";
	for (int i = 0; i < n; i++) cout << e_n[i] << " ";
	cout << endl;

	cout << "\n====================����� ��. � ����. �����================\n";
	x_n[0] = 1;
	for (int i = 1; i < n; i++)
		x_n[i] = x_n[i - 1] + h;


	cout << "����: ";
	for (int i = 0; i < n; i++) cout << x_n[i] << " ";
	cout << endl;

	yMet[0] = V;
	for (int i = 1; i < n; i++) {
		yk = yMet[i - 1] + h * (2 * V * x_n[i - 1] + V * pow(x_n[i - 1], 2));
		yMet[i] = yMet[i - 1] + h * 0.5 * ((2 * V * x_n[i - 1] + V * pow(x_n[i - 1], 2) - yMet[i - 1]) + (2 * V * x_n[i] + V * pow(x_n[i], 2) - yk));
	}

	cout << "������� ��������� �������� ������� (��. � ����. �����)\n";
	for (int i = 0; i < n; i++) cout << yMet[i] << " ";
	cout << endl;

	for (int i = 0; i < n; i++)
		yTochn[i] = V * pow(x_n[i], 2);
	cout << "������ �������: \n";
	for (int i = 0; i < n; i++) cout << yTochn[i] << " ";
	cout << endl;

	for (int i = 0; i < n; i++)
		e_n[i] = yMet[i] - yTochn[i];
	cout << "����������� � �����: \n";
	for (int i = 0; i < n; i++) cout << e_n[i] << " ";
	cout << endl;

	return 0;
}