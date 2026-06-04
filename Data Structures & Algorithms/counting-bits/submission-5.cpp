class Solution {
public:
    vector<int> countBits(int n) {
        
        vector<int>ans(n+1,0);
        int powerOfTwo=1;
        for(int i=1;i<=n;i++)
        {
            if(powerOfTwo*2==i)
            {
                powerOfTwo=i;
            }
            ans[i]=1+ans[i-powerOfTwo];
        }
        return ans;
    }
};
