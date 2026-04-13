class Solution {
    void help(int i,int n,vector<int>&candidates,int target,vector<int>temp,
    set<vector<int>>&ans)
    {
        if(i==n)
        {
            if(target==0)
            {
                sort(temp.begin(),temp.end());
                ans.insert(temp);
            }
            return;
        }
        if(target<0) return;
        
        
            temp.push_back(candidates[i]);
          help(i+1,n,candidates,target-candidates[i],temp,ans);
            temp.pop_back();
         help(i+1,n,candidates,target,temp,ans);
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        int n=candidates.size();
        
        set<vector<int>>ans;
        vector<int>temp;
        help(0,n,candidates,target,temp,ans);
        vector<vector<int>>res;
        for(auto &x:ans)
        {
            res.push_back(x);
        }
        return res;
    }
};
