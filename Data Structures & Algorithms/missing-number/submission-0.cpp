class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int ans=0;
        for(auto x:nums)
        {
            ans^=x;
        }
        int n=nums.size();
        for(int i=1;i<=n;i++)
        {
            ans^=i;
        }
        return ans;
    }
};
