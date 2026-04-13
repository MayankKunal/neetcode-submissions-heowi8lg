class Solution {
    void help(int i,int n,vector<int>&nums,vector<int>temp,vector<vector<int>>&ans)
    {
        if(i==n)
        {
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[i]);
        help(i+1,n,nums,temp,ans);
        temp.pop_back();
        help(i+1,n,nums,temp,ans);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {

     int n=nums.size();
     vector<vector<int>>ans;
     vector<int>temp;
     help(0,n,nums,temp,ans);  
     return ans; 
    }
};
