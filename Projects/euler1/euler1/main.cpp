#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int prime(unsigned long long x);

int main()
{
	unsigned long long result(0), value(600851475143);

	for (unsigned long long i=2; i<600851475143; i++)
	{
		if (600851475143 % i == 0)
		{
			cout << i << "\n";
			if (prime(i))
				result = i;
		}
	}

	cout.setf(ios::fixed);
	cout << setprecision(0) << result;
	std::cin.ignore();

}

int prime(unsigned long long x)
{
	for (unsigned long long i=0; i<x; i++)
	{
		if (x%i == 0)
			return(0);
	}
	return(1);
}