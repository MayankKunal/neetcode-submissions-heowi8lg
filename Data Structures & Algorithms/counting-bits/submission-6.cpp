class Solution {
public:
    vector<int> countBits(int n) {
        
        vector<int>ans(n+1,0);
        int counter=1;
        for(int i=1;i<=n;i++)
        {
            if(counter*2==i)
             {
                 counter*=2;
             }
             ans[i]=1+ans[i-counter];
        }
        return ans;
    }
};
