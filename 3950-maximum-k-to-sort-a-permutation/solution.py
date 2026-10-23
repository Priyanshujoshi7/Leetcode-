class Solution:
    def sortPermutation(self, nums: List[int]) -> int:
        k = -1 # all bits set: nothing misplaced yet
        for i, x in enumerate(nums):
            if x != i:
                k &= x # keep only the bits it shares
                if not k:
                    return 0
        return max(k, 0)
        
