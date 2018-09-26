/*
 * MillerRabin.cpp
 *
 *  Created on: Sep 22, 2018
 *      Author: fanchen
 */

#include "MillerRabin.h"

MillerRabin::MillerRabin(int* tests, int size){
	// constructor
	// add test cases to the class
	for (int i = 0; i < size; i++)
		testCases.push_back(tests[i]);
}

unsigned long long MillerRabin::expoMod(unsigned long long base, int expo, unsigned long long mod){
	// return the remainder of base^expo % mod
	unsigned long long res = 1;
	if (base > mod)
		base %= mod; // reduce base

	while (expo){
		if (expo % 2) // expo is odd, record the current res
			res = (res * base) % mod;
		base = (base * base) % mod;
		expo /= 2;
	}
	return res;
}

bool MillerRabin::millerRabinTest(int testCase, int d, int r, unsigned long long n){
	// Miller-Rabin test for each test case
	unsigned long long x = expoMod(static_cast<unsigned long long>(testCase), d, n); // x stores the initial result of a[i]^d mod n
	if (x == 1 || x == n - 1) // current test case a[i] indicates n might be prime. Go for the next test case
		return true;
	else{
		for (int j = 1; j <= r - 1; j++){ // check (a[i]^d)^2^j) mod n.
			// Only need to check j = 1 to r - 1. If any iteration the remainder becomes n - 1,
			// then stop because the remaining powers guarantees that remainder will remain 1.
			x = (x * x) % n;
			if (x == n - 1)
				return true;
		}
		return false; // none of the check in the previous loop comes out true. Thus this test case fails
	}
}

bool MillerRabin::isPrime(unsigned long long num){
	// determine whether n is prime using Miller-Rabin

	// trivial cases
	if (num % 2 == 0 && num > 2) // n is even
		return false;
	for (auto it = testCases.begin(); it != testCases.end(); it++){
		if (num == *it)
			return true;
	}

	// non-trivial cases
	int d, r = 0;
	// find d such that n - 1 = d * 2^r
	d = num - 1; // set d to n - 1
	while(d % 2 == 0){
		d /= 2;
		r++;
	}

	for (auto it = testCases.begin(); it != testCases.end(); it++){
		if (millerRabinTest(*it, d, r, num))
			continue;
		else
			return false;
	}
	return true;
}

