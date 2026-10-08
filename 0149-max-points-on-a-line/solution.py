class Solution:
    def maxPoints(self, points: list[list[int]]) -> int:
        n = len(points)
        if n <= 2:
            return n
        
        def gcd(a: int, b: int) -> int:
            return a if b == 0 else gcd(b, a % b)
        
        ans = 1
        
        for i in range(n):
            x1, y1 = points[i]
            slope_count = defaultdict(int)
            duplicate = 1
            local_max = 0
            
            for j in range(i + 1, n):
                x2, y2 = points[j]
                if x1 == x2 and y1 == y2:
                    duplicate += 1
                    continue
                
                dx = x2 - x1
                dy = y2 - y1
                g = gcd(dx, dy)
                
                # Reduce by GCD
                dx //= g
                dy //= g
                
                # Normalize sign to keep representation unique
                if dx < 0:
                    dx, dy = -dx, -dy
                elif dx == 0:
                    dy = abs(dy)
                
                slope_count[(dx, dy)] += 1
                local_max = max(local_max, slope_count[(dx, dy)])
            
            ans = max(ans, local_max + duplicate)
            
        return ans

