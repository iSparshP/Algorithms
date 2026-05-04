from typing import List

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        lookup={}
        for idx,num in enumerate(nums):
            complement = target-num
            if complement in lookup:
                return [lookup[complement],idx]
            lookup[num]=idx