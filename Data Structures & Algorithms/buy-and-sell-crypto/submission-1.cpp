class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n=prices.size();
        int profit=0;
        int cp=INT_MAX;
        for(int i=0;i<n;i++)
        {
            cp=min(prices[i],cp);
            profit=max(profit,prices[i]-cp);
        }
        return profit;
    }
};
