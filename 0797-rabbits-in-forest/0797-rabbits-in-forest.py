from collections import defaultdict
class Solution:
    def numRabbits(self, answers: List[int]) -> int:
        freq = defaultdict(int)
        ans=0
        for i in range(len(answers)):
            freq[answers[i]]+=1
        for key, value in freq.items():
            ans += ceil(value / (key + 1)) * (key + 1)
        return ans 
