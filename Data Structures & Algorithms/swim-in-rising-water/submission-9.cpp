class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({grid[0][0],{0,0}});
        int dr[4]={-1,0,1,0};
        int dc[4]={0,-1,0,1};
        vector<vector<int>>vis(n+1,vector<int>(n+1,0));
        int ans=0;
        vis[0][0]=1;
        while(!pq.empty())
        {
            auto it=pq.top();
            pq.pop();
            int node=it.first;
            int row=it.second.first;
            int col=it.second.second;
            vis[row][col]=1;
            ans=max(ans,node);
            if(row==n-1 && col==n-1) return ans;
            for(int i=0;i<4;i++)
            {
                 int nrow=row+dr[i];
                 int ncol=col+dc[i];
                 if(nrow<0 || nrow>=n || ncol<0 || ncol>=n || vis[nrow][ncol]) continue;
                 pq.push({grid[nrow][ncol],{nrow,ncol}});
            }
        }
        return ans;
    }
};
