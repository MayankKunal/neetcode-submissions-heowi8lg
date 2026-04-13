class Solution {
    int help(int i,int n,int buy,vector<int>&prices)
    {
        if(i>=n) return 0;
         
         if(buy)
         {
            return max((help(i+1,n,0,prices)-prices[i]),help(i+1,n,buy,prices));
         }
         else
         return max((help(i+2,n,1,prices)+prices[i]),help(i+1,n,buy,prices));
    }
public:
    int maxProfit(vector<int>& prices) {
        
        int n=prices.size();

     
        return help(0,n,1,prices);
    }
};
