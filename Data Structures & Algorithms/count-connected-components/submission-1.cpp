class Solution {
    void traverseGraph(int node,unordered_map<int,vector<int>>&graph,vector<int>&vis)
    {
        if(vis[node]) return;
        vis[node]=1;
          
          for(auto currNode:graph[node])
          {
            traverseGraph(currNode,graph,vis);
          }
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
             
        
        unordered_map<int,vector<int>>graph;
        for(auto edge:edges)
        {
            int u=edge[0];
            int v=edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
  int count=0;
  vector<int>vis(n,0);
        for(int i=0;i<n;i++)
        {
          if(!vis[i])
          {
            traverseGraph(i,graph,vis);
            count++;
          }
        }
return count;
             
    }
};
