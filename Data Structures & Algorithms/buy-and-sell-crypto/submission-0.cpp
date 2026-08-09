class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int  maxProfit=INT_MIN;
       int price=prices[0];
        int n=prices.size();
        for(int i=0;i<n;i++){
            price=min(prices[i],price);
            maxProfit=max(maxProfit,prices[i]-price);
        }
        return maxProfit;
    }
};
