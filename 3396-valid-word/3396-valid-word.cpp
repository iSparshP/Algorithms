class Solution {
public:
    bool isValid(string word) {
        int n = word.size();
        if (n < 3) return false;

        bool hasVowel = false;
        bool hasConsonant = false;

        for (auto &c : word) {
            if (!(
                (c >= 'a' && c <= 'z') ||
                (c >= 'A' && c <= 'Z') ||
                (c >= '0' && c <= '9')
            )) {
                return false;
            }

            if (isalpha(c)) {
                char lower = tolower(c);
                if (lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u') {
                    hasVowel = true;
                } else {
                    hasConsonant = true;
                }
            }
        }

        return hasVowel && hasConsonant;
    }
};
