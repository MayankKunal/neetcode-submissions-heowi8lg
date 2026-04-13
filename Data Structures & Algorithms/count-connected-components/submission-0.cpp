class Solution {
    void dfs(int src,vector<int>adj[],vector<int>&vis)
    {
        vis[src]=1;
        for(auto adjNode:adj[src])
        {
            if(!vis[adjNode])
            {
                dfs(adjNode,adj,vis);
            }
        }
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
          vector<int>adj[n];

          for(auto edge:edges)
          {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
          }
          vector<int>vis(n,0);
          int count=0;
          for(int i=0;i<n;i++)
          {
            if(!vis[i])
            {
                dfs(i,adj,vis);
                count++;
            }
          }
          return count;
    }
};
