class Solution:
    def totalWaviness(self, num1: int, num2: int) -> int:
        """
        Count the total 'waviness' of numbers in the range [num1, num2].
        Waviness is defined by digit patterns where the middle digit is either
        a peak (greater than both neighbors) or a valley (smaller than both neighbors).
        """

        from functools import lru_cache

        def solve(n: int) -> int:
            # Handle negative input gracefully
            if n < 0:
                return 0

            # Convert number to string for digit-by-digit processing
            s = str(n)

            @lru_cache(None)
            def dfs(pos, started, last, second_last, tight):
                """
                Recursive digit DP (digit dynamic programming).
                Arguments:
                  pos          -> current digit position
                  started      -> whether we've placed a non-leading-zero digit yet
                  last         -> last digit placed
                  second_last  -> digit before last
                  tight        -> whether current prefix is still bounded by 's'
                Returns:
                  (count, waviness_sum) for all valid numbers from this state
                """

                # Base case: reached end of number
                if pos == len(s):
                    return (1, 0)  # one valid number, no waviness contribution

                # Determine digit limit (tight means we cannot exceed current digit in 's')
                limit = int(s[pos]) if tight else 9

                total_cnt = 0  # total count of numbers formed
                total_wav = 0  # total waviness accumulated

                # Try all possible digits at this position
                for d in range(limit + 1):
                    ntight = tight and d == limit  # maintain tightness if equal

                    if not started and d == 0:
                        # Skip leading zeros (still haven't started number)
                        cnt, wav = dfs(
                            pos + 1,
                            False,
                            10,   # placeholder for 'last' when not started
                            10,   # placeholder for 'second_last' when not started
                            ntight
                        )
                        total_cnt += cnt
                        total_wav += wav

                    else:
                        # Check if current digit contributes to waviness
                        add = 0
                        if started and second_last != 10:
                            # If last digit is a peak or valley compared to neighbors
                            if (
                                (last > second_last and last > d) or
                                (last < second_last and last < d)
                            ):
                                add = 1

                        # Update second_last for next recursion
                        n_second_last = last if started else 10

                        # Recurse deeper
                        cnt, wav = dfs(
                            pos + 1,
                            True,
                            d,
                            n_second_last,
                            ntight
                        )

                        total_cnt += cnt
                        total_wav += wav + add * cnt  # add waviness contribution

                return (total_cnt, total_wav)

            # Return total waviness for numbers up to n
            return dfs(0, False, 10, 10, True)[1]

        # Compute waviness in range [num1, num2] using inclusion-exclusion
        return solve(num2) - solve(num1 - 1)

