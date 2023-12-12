#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int a, b, n;
	
	cin >> a >> b;

	int x = a;

	for (int x = a; x <= b; x++) {
		cout << "x(" << x << ") = " << x << endl;
		double s = 0;
		int ntemp = 0;
		double f = 1;

		
		while (abs(f) > 0.0001 ) {
			s += f;

			ntemp += 1;
			f *= 1.0 * x * x / (ntemp*2 - 1) / (ntemp*2) * -1;
			
		}
		cout << "cos = " << cos(x) << endl;
		cout << "S(x" << x << ") = " << s << endl;
		cout << "n(" << x << ") = " << ntemp << endl;
		cout << "=============================================" << endl;
	}
	return 0;
}