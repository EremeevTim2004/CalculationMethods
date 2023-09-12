#include <iostream>
#include "math.h"
using namespace std;

bool checker(int x[], int rez[])
{
	for (int i = 0; i < x.lenght(); i ++)
	{
		for (int j = 0; j < rez.lenght(); j ++)
		{}
	}
}

void printer(int x[], int rez[], int n)
{
	for (int i = 0; i < n; i ++)
	{
		for (int j = 0; j < n; j ++)
		{
			if (j == 3) std::cout << "1 ";
			else std::cout << x[j] << " ";
		}
		std::cout << "| " <<  rez[i] << std::endl;
	}
}

int main()
{
	int n;

	std::cout << "Input col" << std::endl << ":" << ">>";
	std::cin >> n;

	int x[n];
	int rez[n];

	for (int i = 0; i < n; i ++)
	{
		std::cout << "Input x_" << i << ":" << std::endl << ">>";
		std::cin >> x[i];
	}
	for (int i = 0; i < n; i ++)
	{
		std::cout << "Input f(x_" << i << ") result:" << std::endl << ">>";
		std::cin >> rez[i];
	}
	printer(x, rez, n);

	return 0;
}