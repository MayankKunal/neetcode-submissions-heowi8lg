class Solution {
public:
    unordered_map<int, int> shortestPath(int n, vector<vector<int>>& edges, int src) {
        
    vector<pair<int,int>>Adj[n];
    for(auto edge:edges)
    {
        Adj[edge[0]].push_back({edge[1],edge[2]});
    }
unordered_map<int, int>mp;
for(int i=0;i<n;i++)
{
    mp[i]=INT_MAX;
}
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
q.push({src,0});
mp[src]=0;
while(!q.empty())
{
    auto it=q.top();
    q.pop();
    int node=it.first;
    int d=it.second;
   
    for(auto x:Adj[node])
    {
        if(mp[x.first]>(d+x.second))
        {
           mp[x.first]=d+x.second;
           q.push({x.first,d+x.second});
        }
    }
}

for(auto &x:mp)
{
    if(x.second==INT_MAX)
    {
        mp[x.first]=-1;
    }
}
return mp;

    }
};
