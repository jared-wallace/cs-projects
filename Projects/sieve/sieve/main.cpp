#include <iostream>
#include <vector>
#include <cmath>
#include <string.h>

using namespace std;
std::vector<unsigned long> get_primes(unsigned long max);

int main()
{
	unsigned long number;
	cout << "Enter number now\n\n";
	cin >> number;
	vector<unsigned long> primes = get_primes(number);

	for(unsigned long i = 0; i<primes.size(); ++i)
		cout << primes[i] << " ";
	cout << endl;

}