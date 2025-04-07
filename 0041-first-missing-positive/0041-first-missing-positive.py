class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        freq={}
        max_ele=max(nums,default=0)
        for num in nums:
            freq[num]= True
        for i in range(1, max_ele):
            if i not in freq:
                return i
        return 1 if max_ele < 0 else max_ele +1