#include<bits/stdc++.h>
class Solution {
    void help(int i,int n,vector<int>&nums,vector<int>temp,vector<vector<int>>&ans)
    {
        if(i==n)
        {
            sort(temp.begin(),temp.end());
            if(ans.empty() ||ans.back()!=temp)
            ans.push_back(temp);
            return;
        }
        
        temp.push_back(nums[i]);
        help(i+1,n,nums,temp,ans);
        temp.pop_back();
        help(i+1,n,nums,temp,ans);
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
  sort(nums.begin(),nums.end());
     int n=nums.size();
     vector<vector<int>>ans;
     vector<int>temp;
     help(0,n,nums,temp,ans);  
     sort(ans.begin(),ans.end());
     vector<vector<int>>res;
     for(int i=0;i<ans.size();i++)
     {
        if(i>0 && ans[i]!=ans[i-1])
            res.push_back(ans[i]);
        
     }
     res.push_back({});
    return res;
    
    }
};
