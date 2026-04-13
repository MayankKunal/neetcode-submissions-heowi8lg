class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(auto x:nums)
        {
            mp[x]++;
        }
        vector<pair<int,int>>res;
        for(auto &x:mp)
        {
            res.push_back({x.second,x.first});
        }
        vector<int>ans;
        sort(res.rbegin(),res.rend());
       int i=0;
        while(i<k)
        {
            ans.push_back(res[i].second);
            i++;
        }
        return ans;
    }
};
