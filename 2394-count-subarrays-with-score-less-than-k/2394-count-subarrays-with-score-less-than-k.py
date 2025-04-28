class Solution:
    def countSubarrays(self, nums: List[int], k: int) -> int:
        count = 0
        n = len(nums)
        total=0
        l=0
        for r in range(n):
            total += nums[r]
            while l<=r and total * (r-l+1)>=k:
                total-=nums[l]
                l+=1
            count+=(r-l+1)
        return count
