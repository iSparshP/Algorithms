class Solution:
    def climbStairs(self, n: int) -> int:
        if n<= 3:
            return n
        
        prev1 , prev2 = 3,2
        for _ in range(3,n):
            curr = prev1 + prev2
            prev2=prev1
            prev1=curr
        return curr