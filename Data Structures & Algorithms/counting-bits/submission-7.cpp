class Solution {
public:
    vector<int> countBits(int n) {
        
          vector<int>ans(n+1,0);
          int power2=1;
          for(int i=1;i<=n;i++)
          {
             if((power2*2)==i)
             {
                power2*=2;
             }
             ans[i]=1+ans[i-power2];
          }
          return ans;
    }
};
