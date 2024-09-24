class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLength=0;
        int left=0;
        unordered_map<char,int>lastseen;
        for(int right=0;right<s.length();right++){
            char c=s[right];
            if(lastseen.find(c)!=lastseen.end() && lastseen[c]>=left){
                left=lastseen[c]+1;
            }
            maxLength=max(maxLength,right-left+1);
            lastseen[c]=right;
        }
        return maxLength;
    }
};