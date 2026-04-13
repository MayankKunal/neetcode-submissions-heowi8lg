class Solution {
    int help(int i,int j,int n,int m,vector<vector<int>>&grid)
    {

        if(i<0 || i>=n || j<0 || j>=m || grid[i][j]==0) return 0;

        grid[i][j]=0;

     return 1+help(i+1,j,n,m,grid)+help(i-1,j,n,m,grid)+
     help(i,j+1,n,m,grid)+help(i,j-1,n,m,grid);

    }
    int bfs(int i,int j,int n,int m,vector<vector<int>>&grid)
    {
        queue<pair<int,int>>q;
        int dr[4]={0,-1,0,1};
        int dc[4]={-1,0,1,0};
        q.push({i,j});
        int ans=0;
        grid[i][j]=0;
        while(!q.empty())
        {
            auto it=q.front();
            q.pop();
            int row=it.first;
            int col=it.second;
            ans++;
            for(int i=0;i<4;i++)
            {
                int nrow=row+dr[i];
                int ncol=col+dc[i];
                if(nrow<0 || nrow>=n || ncol<0 || ncol>=m || grid[nrow][ncol]==0)
                {
                    continue;
                }
                grid[nrow][ncol]=0;
                q.push({nrow,ncol});
            }
        }

        return ans;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        

        int n=grid.size();
        int m=grid[0].size();
     int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                ans=max(ans,bfs(i,j,n,m,grid));
            }
        }
        return ans;
    }
};
