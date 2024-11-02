class Solution {
public:
    bool isCircularSentence(string sentence) {
        // stringstream ss(sentence);
        // string word;
        // vector<string> words;
        // while(ss>>word){
        //     words.push_back(word);
        // }
        // int n=words.size();
        // char last = words[n-1].back();
        // for(int i=0;i<n;i++){
        //     if(words[i].front()!=last) return false;
        //     last = words[i].back();
        // }
        // return true;
        for(int i=0;i<sentence.size();i++){
            if(sentence[i]==' ' && sentence[i-1] != sentence[i+1]){
                return false;
            }
        }
        return sentence[0] == sentence[sentence.size()-1];
    }
};