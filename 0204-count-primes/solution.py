class Solution:
    def countPrimes(self, n: int) -> int:
        if n <= 2:
            return 0
        
        # Initialize a boolean array tracking prime status
        # True means the index is prime, False means composite
        is_prime = [True] * n
        is_prime[0] = is_prime[1] = False
        
        # Loop up to the square root of n
        for i in range(2, int(n**0.5) + 1):
            if is_prime[i]:
                # Mark all multiples of i starting from i*i as non-prime
                for j in range(i * i, n, i):
                    is_prime[j] = False
                    
        # The number of True values represents the count of primes
        return sum(is_prime)

            
        
