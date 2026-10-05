class Solution:
    def closestPrimes(self, left: int, right: int) -> list[int]:
        # Step 1: Sieve of Eratosthenes up to 'right'
        is_prime = [True] * (right + 1)
        is_prime[0] = is_prime[1] = False
        
        for i in range(2, int(right**0.5) + 1):
            if is_prime[i]:
                for j in range(i * i, right + 1, i):
                    is_prime[j] = False
                    
        # Step 2: Collect all primes within the [left, right] range
        primes = [i for i in range(left, right + 1) if is_prime[i]]
        
        # If there are fewer than 2 primes, a valid pair doesn't exist
        if len(primes) < 2:
            return [-1, -1]
        
        # Step 3: Find the closest pair
        min_gap = float('inf')
        ans = [-1, -1]
        
        for i in range(len(primes) - 1):
            gap = primes[i+1] - primes[i]
            if gap < min_gap:
                min_gap = gap
                ans = [primes[i], primes[i+1]]
                
                # Optimization: The smallest possible gap between primes > 2 is 2 (Twin Primes).
                # If we find a gap of 2 (or 1, in the case of [2, 3]), we can return immediately.
                if min_gap <= 2:
                    return ans
                    
        return ans

