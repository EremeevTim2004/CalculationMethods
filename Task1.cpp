#include <iostream>
#include "math.h"
using namespace std;

function(const int x)
{
	int count = 1;
	if (x == 0) std::cout << 0 << "\t\t";
	else
	{
		double partSum = x;
		double intermediateMember = x;
		double eps = 0.001;
		
		double numerator = x;
		double denominator = 1;

		bool flag = true;

		for (int i = 1; abs(intermediateMember) > eps; i += 2)
		{
			numerator *= x * x;
			denominator *= (i + 1) * (i + 2);
			
			intermediateMember = numerator / denominator;
			
			if (flag) intermediateMember *= (-1);
			flag = !flag;

			partSum += intermediateMember;
			count += 1;
		}
		std::cout << partSum << "\t\t";
	}
	return count;
}

void printer(const int lBorder, const int rBorder, const int rate)
{
	std::cout << std::fixed;
	std::cout.precision(2);

	int* counts = new int[(int)((rBorder - lBorder + 1) / rate)];
	
	for (int i = lBorder; i <= rBorder; i += rate)
		std::cout << i << "\t\t";
	std::cout << std::endl;
	
	for (int i = lBorder, j = 0; j <= rBorder; i += rate, j ++)
		counts[j] = function(i);
	std::cout << std::endl;
	
	for (int i = 0; i < (int)((rBorder - lBorder + 1) / rate); i ++)
		std::cout << counts[i] << "\t\t";
	std::cout << std::endl;
}

int main()
{
	int left = 0;
	int rigth = 0; 
	int rate = 0;

	std::cout << "Input left side." << std::endl << ">>";
	std::cin >> left;
	std::cout << "Input right side." << std::endl << ">>";
	std::cin >> rigth;
	std::cout << "Input rate." << std::endl << ">>";
	std::cin >> rate;

	printer(left, rigth, rate);

	return 0;
}
