class Solution {
    bool help(int src,int parent,vector<int>adj[],vector<int>&vis)
    {
        vis[src]=1;
        for(auto adjNode:adj[src])
        {
            if(!vis[adjNode])
            {
                if(help(adjNode,src,adj,vis)) return true;
            }
            else if(adjNode!=parent)
            {
                return true;
            }
        }
        return false;
    }
public:
    bool validTree(int n, vector<vector<int>>& edges) {
          
          if(edges.size()!=n-1) return false;
          vector<int>adj[n];
          for(auto edge:edges)
          {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
          }

          vector<int>vis(n,0);
          for(int i=0;i<n;i++)
          {
            if(!vis[i])
            {
                if(help(i,-1,adj,vis)) return false;
            }
          }
          return true;
    }
};
