class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n=A.size();
        vector<int>freq(n);
        unordered_set<int> eleA,eleB;
        for(int i=0;i<n;i++){
            eleA.insert(A[i]);
            eleB.insert(B[i]);
            int count=0;
            for(int ele:eleA){
                if(eleB.count(ele)){
                    count++;
                }
            }
            freq[i]=count;
        }
        return freq;
    }
};