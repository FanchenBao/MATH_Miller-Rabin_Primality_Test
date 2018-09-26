'''
Author: Fanchen Bao
Date: 09/26/2018

template for Miller-Rabin Primality Test
'''

class MillerRabin:
    ''' class for carrying out the Miller-Rabin primality test '''
    def __init__(self, testCases = [2, 7, 61]):
        self.testCases = testCases[:] # copy the user supplied testCases (must be an int list). Default test cases are 2, 7, and 61

    def expoMod(self, base, expo, mod):
        ''' calculate the remainder of this equation base^expo % mod '''
        res = 1
        base %= mod # reduce base
        
        while expo:
            if expo % 2: # exponent is odd
                res = (res * base) % mod
            base = (base**2) % mod
            expo //= 2
        return res

    def millerRabinTest(self, d, r, n, test):
        ''' testing individual test case. n is the number to be tested.
            d and r is used to express n - 1, in which n - 1 = d * 2^r
        '''
        x = self.expoMod(test, d, n) # x stores the remainder of test^d % n
        if x == 1 or x == n - 1: # test passes
            return True
        else:
            for i in range(1, r): # testing additional r - 1 times 
                x = (x**2) % n
                if x == n - 1:
                    return True
            return False # testing fails, i.e. n must be composite

    def isPrime(self, n):
        ''' teting whether the given n is prime '''
        for p in self.testCases: # test cases must all be prime and start with 2
            if n == p:
                return True
        if n > 2 and n % 2 == 0:
            return False

        r = 0
        d = n - 1
        while d % 2: # get d and r such that n - 1 = d * 2^r
            d //= 2
            r += 1
        
        for test in self.testCases:
            if self.millerRabinTest(d, r, n, test):
                continue
            else:
                return False
        return True
