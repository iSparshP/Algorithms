class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n=s.size();
        vector<int>temp(n+1,0);
        for(auto& itr:shifts){
            if(itr[2]==0){
                temp[itr[0]]--;
                temp[itr[1]+1]++;
            }
            else{
                temp[itr[0]]++;
                temp[itr[1]+1]--;
            }
        }
        int curr=0;
        for(int i=0;i<n;i++){
            curr+=temp[i];
            temp[i]=curr;
        }
        for(int i=0;i<n;i++){
            int Net=(temp[i]%26+26)%26;
            s[i]='a'+(s[i]-'a'+Net)%26;
        }
        return s;
    }
};

// class Solution {
// public:
//     string shiftingLetters(string s, vector<vector<int>>& shifts) {
//         int n = s.size();
//         vector<int> shiftCounts(n + 1, 0); 

//         for (auto& shift : shifts) {
//             int start = shift[0];
//             int end = shift[1];
//             int direction = shift[2];

//             if (direction == 0) {  // Left shift
//                 shiftCounts[start]--;
//                 shiftCounts[end + 1]++; 
//             } else {  // Right shift
//                 shiftCounts[start]++;
//                 shiftCounts[end + 1]--; 
//             }
//         }

//         int currentShift = 0;
//         for (int i = 0; i < n; i++) {
//             currentShift += shiftCounts[i];
//             shiftCounts[i] = currentShift; 

//             int netShift = shiftCounts[i] % 26;
//             s[i] = 'a' + (s[i] - 'a' + netShift) % 26;
//         }

//         return s;
//     }
// };