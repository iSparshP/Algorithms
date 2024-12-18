class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice=INT_MAX;
        int maxPrice=0;
        for(auto &price:prices){
            minPrice=min(minPrice,price);
            maxPrice=max(maxPrice,price-minPrice);
        }
        return maxPrice;
    }
};