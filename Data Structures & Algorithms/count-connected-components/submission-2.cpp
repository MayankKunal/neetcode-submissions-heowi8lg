class Solution {
    int findParent(int a,vector<int>&parent)
    {
        if(a==parent[a]) return a;
        return parent[a]=findParent(parent[a],parent);
    }
    bool isConnected(int a,int b,vector<int>&parent,vector<int>&graphSize)
    {
        int parentA=findParent(a,parent);
        int parentB=findParent(b,parent);
        if(parentA==parentB) return true;
        if(graphSize[parentA]>=graphSize[parentB])
        {
            parent[parentB]=parentA;
            graphSize[parentA]+=graphSize[parentB];
        }
        else
        {
            parent[parentA]=parentB;
            graphSize[parentB]+=graphSize[parentA];
        }
        return false;
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
  int count=n;
  vector<int>parent(n,0),graphSize(n,1);
  for(int i=0;i<n;i++)
  {
    parent[i]=i;
  }
        for(auto edge:edges)
        {
          if(!isConnected(edge[0],edge[1],parent,graphSize))
          {
            count--;
          }
        }
return count;
             
    }
};
