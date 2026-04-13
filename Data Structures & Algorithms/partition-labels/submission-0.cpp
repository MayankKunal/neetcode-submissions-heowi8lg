class Solution {
public:
    vector<int> partitionLabels(string s) {
        
        unordered_map<int,pair<int,int>>mp;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            if(mp.find(s[i])!=mp.end())
            {
                mp[s[i]]={mp[s[i]].first,i};
            }
            else
            mp[s[i]]={i,-1};
        }
       vector<pair<int,int>>v;
        for(auto &x:mp)
        {
             v.push_back({x.second.first,x.second.second});
        }
        sort(v.begin(),v.end());
        int st=v[0].first;
        int e=v[0].second;
        vector<int>ans;
        for(int i=1;i<v.size();i++)
        {
            if(v[i].first<e)
            {
                e=max(e,v[i].second);
                st=min(st,v[i].first);
            }
            else
            {
                int val=e-st;
                if(val<0) val=0;
                ans.push_back(val+1);
                st=v[i].first;
                e=v[i].second;
            }
        }
        int val=e-st;
                if(val<0) val=0;
                ans.push_back(val+1);
        return ans;
        
    }
};
