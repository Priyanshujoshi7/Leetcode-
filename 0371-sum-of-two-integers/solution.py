class Solution:
    def getSum(self, a: int, b: int) -> int:

        # Mask to bound the number to 32 bits
        mask = 0xFFFFFFFF

        while b != 0:
            carry = (a & b) << 1
            a = (a ^ b) & mask
            b = carry & mask

        # if the 23nd bit is 1, the number is neagive in 2's compliment 
        return a if  a <=  0x7FFFFFFF else ~(a ^ mask)
        
