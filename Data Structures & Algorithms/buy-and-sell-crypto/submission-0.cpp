class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int profit=0,cp=INT_MAX;
        for(int i=0;i<n;i++)
        {
            cp=min(cp,prices[i]);
            profit=max(profit,prices[i]-cp);
        }
        return profit;
    }
};
