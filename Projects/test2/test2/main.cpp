#include <vector>
#include <cmath>
#include <string.h>
#include <iostream>

std::vector<unsigned long> get_primes(unsigned long max){
    std::vector<unsigned long> primes;
    char *sieve;
    sieve = new char[max/8+1];
    // Fill sieve with 1  
    memset(sieve, 0xFF, (max/8+1) * sizeof(char));
    for(unsigned long x = 2; x <= max; x++)
        if(sieve[x/8] & (0x01 << (x % 8))){
            primes.push_back(x);
            // Is prime. Mark multiplicates.
            for(unsigned long j = 2*x; j <= max; j += x)
                sieve[j/8] &= ~(0x01 << (j % 8));
        }   
    delete[] sieve;
    return primes;
}

int main() {
   std::vector<unsigned long> primes = get_primes(100000000000000000);

   for (int i = 0; i<primes.size(); ++i)
      std::cout << primes[i] << " ";

   std::cout << std::endl;
}
