class Solution {
public:
    int Lower(int l,int r,vector<int>& potions,int low){
        int possibleIndex=-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(potions[mid]>=low){
                possibleIndex=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return possibleIndex;
    }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n=spells.size();
        int m=potions.size();
        vector<int> ans;
        sort(potions.begin(),potions.end());
        int high=potions[m-1];
        for(int i=0;i<n;i++){
            int spell=spells[i];
            long long low=ceil((1.0*success)/spell);
            if(low>high){
                ans.push_back(0);
                continue;
            }
            int index=Lower(0,m-1,potions,low);
            int count=m-index;
            ans.push_back(count);
        }
        return ans;
    }
};