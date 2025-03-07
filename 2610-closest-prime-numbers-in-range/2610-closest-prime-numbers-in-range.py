class Solution:
    def Sieve(self, num: int) -> list[int]:
        if num < 2:
            return []
        primes = [True] * (num + 1)
        primes[0] = primes[1] = False
        for p in range(2, int(num**0.5) + 1):
            if primes[p]:
                for i in range(p * p, num + 1, p):
                    primes[i] = False
        result = [i for i in range(2, num + 1) if primes[i]]
        return result

    def closestPrimes(self, left: int, right: int) -> list[int]:
        primes = self.Sieve(right)
        closest = float('inf')
        result = [-1, -1]
        prev_prime = -1
        for prime in primes:
            if prime >= left:
                if prev_prime != -1:
                    diff = prime - prev_prime
                    if diff < closest:
                        closest = diff
                        result = [prev_prime, prime]
                prev_prime = prime
        return result