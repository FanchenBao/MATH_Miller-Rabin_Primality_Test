#ifndef MILLER_RABIN_H
#define MILLER_RABIN_H

#include <iostream>
#include <vector>

class MillerRabin{
	// Use the Miller-Rabin primality test to determine whether a given number is prime.
	// Upper limit for determination is set to the size limit of unsigned long long.
	// User must provide the number to be checked, and a list of test cases (available at https://en.wikipedia.org/wiki/Miller%E2%80%93Rabin_primality_test) based on how big the given number is.

public:
	// construtor
	// Precondition: a static C-style int array and its size are passed to the function
	// Postcondition: the values in the array added to the testCases vector.
	// Description: use this function to add individual test cases to the object
	MillerRabin(int* tests, int size);

	// Precondition: three unsigned long long variables passed to the function.
	// Postcondition: return the remainder after 'mod' divides 'base' raised to 'expo' power.
	// Description: handy function to perform base^expo % mod
	unsigned long long expoMod(unsigned long long base, int expo, unsigned long long mod);

	// Precondition: one specific testCase, the number to be checked, and special number d and r (acquired from isPrime()) are passed
	// Postcondition: return true if the testCase passes, otherwise false.
	// Description: testCase passes means n MIGHT be prime, but fails means n DEFINITELY NOT prime
	bool millerRabinTest(int testCase, int d, int r, unsigned long long n);

	// Precondition: the number to be checked is passed. The testCases vector must be initialized (call addTestCases() to initialize testCases).
	// Postcondition: return true if n is prime, false otherwise
	// Description: the main function to determine primality of n.
	bool isPrime(unsigned long long num);

private:
	std::vector<int> testCases;
};


#endif
