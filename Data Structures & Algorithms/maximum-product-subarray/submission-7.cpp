class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int n=nums.size();
        int mini=1;
        int maxi=1;
        int ans=nums[0];
        for(int i=0;i<n;i++)
        {
            int temp=mini*nums[i];
            mini=min(mini*nums[i],min(nums[i],maxi*nums[i]));
            maxi=max(temp,max(nums[i],maxi*nums[i]));
            ans=max(max(mini,ans),maxi);
        }
        return ans;
    }
};
