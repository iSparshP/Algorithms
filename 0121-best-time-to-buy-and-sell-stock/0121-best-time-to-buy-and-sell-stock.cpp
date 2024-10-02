class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice=INT_MAX;
        int maxProfic=0;
        for(auto& price:prices){
            minPrice=min(minPrice,price);
            maxProfic=max(maxProfic,price-minPrice);
        }
        return maxProfic;
    }
};