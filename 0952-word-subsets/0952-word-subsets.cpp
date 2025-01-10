class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> maxFreq(26, 0); 
        for (string& word : words2) {
            vector<int> currFreq(26, 0);
            for (char c : word) {
                currFreq[c - 'a']++;
            }
            for (int i = 0; i < 26; i++) {
                maxFreq[i] = max(maxFreq[i], currFreq[i]);
            }
        }

        vector<string> ans;
        for (string& word : words1) {
            vector<int> currFreq(26, 0);
            for (char c : word) {
                currFreq[c - 'a']++;
            }

            bool isUniversal = true;
            for (int i = 0; i < 26; i++) {
                if (currFreq[i] < maxFreq[i]) {
                    isUniversal = false;
                    break;
                }
            }

            if (isUniversal) {
                ans.push_back(word);
            }
        }

        return ans;
    }
};