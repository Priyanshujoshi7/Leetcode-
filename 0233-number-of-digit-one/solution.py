class Solution:
    def countDigitOne(self, n: int) -> int:
        count = 0
        i = 1
        while i <= n:
            divider = i * 10
            # Count complete groups of 'divider' size
            count += (n // divider) * i
            # Handle the remaining partial group
            count += min(max(n % divider - i + 1, 0), i)
            i *= 10
        return count

            
        
