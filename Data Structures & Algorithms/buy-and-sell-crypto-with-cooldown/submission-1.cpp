class Solution {
    int help(int i,int n,bool buy,vector<int>&prices)
    {
        if(i>=n) return 0;
       int ans=0;
       int coolDown=help(i+1,n,buy,prices);
        if(buy)
        {
            ans=max((help(i+1,n,0,prices)-prices[i]),coolDown);
        }
        else
        ans=max((help(i+2,n,1,prices)+prices[i]),coolDown);

         return ans; 
    }
public:
    int maxProfit(vector<int>& prices) {
        
        int n=prices.size();
        return help(0,n,1,prices);

    }
};
