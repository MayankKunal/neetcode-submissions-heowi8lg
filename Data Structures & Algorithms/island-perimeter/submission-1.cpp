class Solution {
    int faces(int r,int c,int n,int m,vector<vector<int>>&grids)
    {
        int faces=4;
      int dr[4]={-1,0,1,0};
      int dc[4]={0,1,0,-1};
      for(int i=0;i<4;i++)
      {
        int row=r+dr[i];
        int col=c+dc[i];
        if(row>=0 && col>=0 && row<n && col<m && grids[row][col]==1)
        {
            faces--;
        }
      }
        return faces;
    }
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
         
         int len=0;
         int ans=0;
         for(int i=0;i<n;i++)
         {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    ans+=faces(i,j,n,m,grid);
                }
            }
         }
         return ans;
        
    }
};