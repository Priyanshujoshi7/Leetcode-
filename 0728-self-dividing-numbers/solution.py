class Solution:
    def selfDividingNumbers(self, left: int, right: int) -> List[int]:

        def is_self_dividing(num):
            temp = num

            while temp > 0:
                digit = temp % 10

                # Digit cannot be 0 and must divide the original number
                if digit == 0 or num % digit != 0:
                    return False

                temp //= 10

            return True

        # Collect all self-dividing numbers in the range
        return [x for x in range(left, right + 1) if is_self_dividing(x)]
