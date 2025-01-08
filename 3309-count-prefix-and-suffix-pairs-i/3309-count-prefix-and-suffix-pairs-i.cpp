class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int count = 0;
        int n = words.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (isPrefixAndSuffix(words[i], words[j])) {
                    count++;
                }
            }
        }
        return count;
    }

private:
    bool isPrefixAndSuffix(const string& word1, const string& word2) {
        int len1 = word1.size();
        int len2 = word2.size();
        if (len1 > len2) { 
            return false; 
        }
        return word2.substr(0, len1) == word1 && 
               word2.substr(len2 - len1, len1) == word1; 
    }
};