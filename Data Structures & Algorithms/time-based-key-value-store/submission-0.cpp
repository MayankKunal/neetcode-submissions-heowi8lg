class TimeMap {
public:
  unordered_map<string,vector<pair<int,string>>>mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        
        vector<pair<int,string>>temp=mp[key];
             sort(temp.begin(),temp.end());
             int l=0,r=temp.size()-1;
             string ans="";
             while(l<=r)
             {
                int mid=(l+r)/2;
                 if(temp[mid].first<=timestamp)
                 {
                    ans=temp[mid].second;
                    l=mid+1;
                 }
                 else
                 {
                    r=mid-1;
                 }
             }
             return ans;
    }
};
