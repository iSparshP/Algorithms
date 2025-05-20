from typing import List

class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        counts = {}                       # don’t shadow built-in name `map`
        threshold = len(nums) // 2       # majority threshold
        
        # 1) Build counts
        for num in nums:
            counts[num] = counts.get(num, 0) + 1
        
        # 2) Find the element whose count exceeds n/2
        for num, cnt in counts.items():  # iterate over key/value pairs
            if cnt > threshold:
                return num               # return immediately
        
        # problem guarantees a majority element, but to satisfy function signature:
        return -1
