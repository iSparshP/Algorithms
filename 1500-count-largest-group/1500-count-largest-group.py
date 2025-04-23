from collections import defaultdict

class Solution:
    def countLargestGroup(self, n: int) -> int:
        def sum_of_digit(x: int) -> int:
            total = 0
            while x:
                total += x % 10
                x //= 10
            return total

        freq = defaultdict(int)

        for i in range(1, n + 1):
            digit_sum = sum_of_digit(i)
            freq[digit_sum] += 1

        max_freq = max(freq.values())
        return sum(1 for count in freq.values() if count == max_freq)
