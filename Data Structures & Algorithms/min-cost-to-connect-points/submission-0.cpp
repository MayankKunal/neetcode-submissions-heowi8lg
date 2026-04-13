class Solution {
    int findParent(int node,vector<int>&parent)
    {
        if(node==parent[node]) return node;

        return parent[node]=findParent(parent[node],parent);
    }
void unionBySize(int node1,int node2,vector<int>&parent,vector<int>&sz)
{
    int parentNode1=findParent(node1,parent);
    int parentNode2=findParent(node2,parent);
    if(parentNode1==parentNode2) return;
    if(sz[parentNode1]>=sz[parentNode2])
    {
        sz[parentNode1]+=sz[parentNode2];
        parent[parentNode2]=parentNode1;
    }
    else
    {
        sz[parentNode2]+=sz[parentNode1];
        parent[parentNode1]=parentNode2;
    }

    return;
}
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        
        vector<vector<int>>edges;
          int n=points.size();
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int dis=abs(points[j][0]-points[i][0])+abs(points[j][1]-points[i][1]);

                edges.push_back({dis,i,j});
            }
        }
 int ans=0;
 vector<int>parent(n);
 vector<int>sz(n,1);
 for(int i=0;i<n;i++) parent[i]=i;
 sort(edges.begin(),edges.end());
        for(auto edge:edges)
        {
            int wt=edge[0];
            int u=edge[1];
            int v=edge[2];

            if(findParent(u,parent)!=findParent(v,parent))
            {
                ans+=wt;
                unionBySize(u,v,parent,sz);
            }
        }
        return ans;
    }
};
