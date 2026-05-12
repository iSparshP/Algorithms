from collections import defaultdict


class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        freq = defaultdict(int)
        left = 0
        ans = 0
        for right in range(len(s)):
            char = s[right]
            freq[char] = freq.get(char, 0) + 1

            while freq[char] > 1:
                freq[s[left]] -= 1
                left += 1
            ans = max(ans, right - left + 1)

        return ans
