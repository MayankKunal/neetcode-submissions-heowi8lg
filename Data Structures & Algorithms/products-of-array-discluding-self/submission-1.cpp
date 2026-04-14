class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
           
           int n=nums.size();
           vector<int>prefix(n,1),suffix(n,1);

           for(int i=0;i<n;i++)
           {
            if(i==0) continue;
              prefix[i]=nums[i-1]*prefix[i-1];
              suffix[n-i-1]=nums[n-i]*suffix[n-i];
           }
         vector<int>ans(n);
           for(int i=0;i<n;i++)
           {
            ans[i]=prefix[i]*suffix[i];
           }

           return ans;
    }
};
