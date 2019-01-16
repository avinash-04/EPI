/*
 * GeneratePrimeNumber.cpp
 *
 *  Created on: Jan 15, 2019
 *      Author: Avinash
 */
#include<iostream>
#include<vector>
#include <cmath>

using namespace std;

bool checkPrime(int n) {

  for (int i = 2; i < sqrt(n); i++) {

    if (n%i == 0) {
      return false;
    }
  }

  return true;
}

vector<int> GeneratePrimeNumbers2(int n)
{
     vector<int> primes;
     vector<bool> isPrimes(n+1, true);

     //set 0 and 1 as false
     isPrimes[0] = false;
     isPrimes[1] = false;

     for(int i=2; i<=n; i++) {

    	 if(isPrimes[i]== false) continue;

    	 if(checkPrime(i)) {
             primes.push_back(i);
    		 for(int j=2*i; j<=n ;j+=i){
    			 isPrimes[j] = false;
    		 }
    	 }
     }

     return primes;
}

//
// check page-72
// Even numbers are eliminated and only odd numbers status is stored
// in isPrimes. Odd number from 3 ...2i+3 (i->0 to n-3/2)
//
vector<int> GeneratePrimeNumbers(int n)
{
     vector<int> primes;
     int sz = (n-3)/2 + 1;
     vector<bool> isPrimes(sz, true);

     primes.push_back(2);

     for(int i=0; i<sz; i++) {

    	 if(isPrimes[i]== false) continue;

    	 if(checkPrime(i)) {


    		 int oddNum = 2*i+3;
    		 primes.push_back(oddNum);
    		 //
             // if oddNum is p & p is prime.
    		 // all the  numbers like 2*p, 3*p ....p*p ....upto n are not prime
    		 // 2*p, 4*p, 6*p is even...eliminated
             // 3*p, 6*p, 9*p....k*p ...where k<p is already marked false by odd numbers that come before p
    		 // so mark it from p*p till n

    		 //
    		 // p*p ---> (2*i+3)(2*i+3) = 4*i^2 + 12*i + 9.
    		 // Index z in isPrimes represents odd number 2*z+3
    		 // so the index z of p*p will be
    		 // 2*z+3 = 4*i^2+12*i+9
    		 // z = 2*i^2+6*i+3
    		 long I = static_cast<long>(i);
    		 for(long j=I*I*2+6*I+3; j<sz; j+=oddNum){
    			 isPrimes[j] = false;
    		 }
    	 }
     }

     return primes;
}
#if 0
int main()
{

	auto vec = GeneratePrimeNumbers(16);

	for(auto a:vec)
	{
		cout << a << " ";
	}

	return 0;
}
#endif

