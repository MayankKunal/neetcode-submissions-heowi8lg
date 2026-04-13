class Solution {
    void help(int i,int j,int n,int m,vector<vector<int>>&grid,int& area)
    {
        if(i==n || i<0 || j==m || j<0 || grid[i][j]==0) return;
        grid[i][j]=0;
        area++;
        help(i+1,j,n,m,grid,area);
        help(i-1,j,n,m,grid,area);
        help(i,j+1,n,m,grid,area);
        help(i,j-1,n,m,grid,area);
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
                {  int area=0;
                    help(i,j,n,m,grid,area);
                    ans=max(area,ans);
                }
            }
        }
        return ans;
    }
};
