class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        numMap = {}
        n=len(nums)
        for i in range(n):
            comp=target-nums[i]
            if comp in numMap:
                return [numMap[comp],i]
            numMap[nums[i]]=i
        return []