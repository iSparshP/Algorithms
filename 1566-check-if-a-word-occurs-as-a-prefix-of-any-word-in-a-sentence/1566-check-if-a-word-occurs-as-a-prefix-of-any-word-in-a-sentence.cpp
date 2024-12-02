class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        stringstream ss(sentence);
        string curr;
        int wordP=1;
        while(ss>>curr){
            if(curr.length()>=searchWord.length() && curr.compare(0,searchWord.length(),searchWord)==0){
                return wordP;
            }
            wordP++;
        }
        return -1;
    }
};