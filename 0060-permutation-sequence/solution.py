import math

class Solution:
    def getPermutation(self, n: int, k: int) -> str:
        # Convert k to 0-indexed to work with division and modulo math
        k -= 1
        
        # Create a list of available digits to pick from
        numbers = [str(i) for i in range(1, n + 1)]
        permutation = []
        
        # Precompute the factorial for (n-1)! to save iterations
        fact = math.factorial(n - 1)
        
        for i in range(n - 1, 0, -1):
            # Determine the index of the next digit in the numbers list
            index = k // fact
            permutation.append(numbers.pop(index))
            
            # Update k and calculate the next factorial size
            k %= fact
            fact //= i
            
        # Append the final remaining digit
        permutation.append(numbers[0])
        
        return "".join(permutation)

