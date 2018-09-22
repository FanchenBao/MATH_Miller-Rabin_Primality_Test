# MATH_Miller-Rabin_Primality_Test
A class to conduct Miller-Rabin primality test on any given integer smaller than 2^64-1

## How to Use
* Initialize the class with an C-style static int array that contains the desired test cases, and the number of test cases. All test cases for reasonable use can be found at [Miiler-Rabin primality test](https://en.wikipedia.org/wiki/Miller%E2%80%93Rabin_primality_test).
  * E.g. 
  ```c++
  int testCases[3] = {2, 7, 61};
  MillerRabin primeTest(testCases, 3);
  ```
* Call the isPrime(n) function to check the primality of number n. n must be no larger than 2^64 - 1 (i.e. max of unsigned long long)
  * E.g.
  ```c++
  int testCases[3] = {2, 7, 61};
  MillerRabin primeTest(testCases, 3);
  
  unsigned long long n = 776531401;
  std::cout << primeTest.isPrime(n) << std::endl;
  // output: 1
  ```
* Complexity: O(3klog(n)), where k is the number of test cases (depending on how big n is), and n is the number to be tested. The three log(n) attributes to two cases of modular exponentiation and finding d and r to represent n - 1.
