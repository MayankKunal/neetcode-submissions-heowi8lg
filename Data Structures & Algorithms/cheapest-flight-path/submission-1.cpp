class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<pair<int,int>>adj[n];
        for(auto flight:flights)
        {
            adj[flight[0]].push_back({flight[1],flight[2]});
        }
        vector<int>vec(n,INT_MAX);
        queue<pair<int,pair<int,int>>>q;
        q.push({src,{0,0}});
        vec[src]=0;
        while(!q.empty())
        {
            
            auto it=q.front();
            q.pop();
            int node=it.first;
            int d=it.second.first;
            int level=it.second.second;
            if(level>k) continue;
            for(auto adjNode:adj[node])
            {
                  int currNode=adjNode.first;
                  int dis=adjNode.second;
                  if(vec[currNode]>d+dis)
                  {
                    q.push({currNode,{d+dis,level+1}});
                    vec[currNode]=d+dis;
                  }
            }
        }


        return vec[dst]==INT_MAX?-1:vec[dst];
        
    }
};
