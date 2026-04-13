class Solution {
    void dfs(int row,int col,int n,int m,vector<vector<int>>&vis,vector<vector<int>>&heights,int prevHeight)
    {
        if( row<0 || row==n || col<0 || col==m || vis[row][col] ||heights[row][col]< prevHeight)
        return;

        vis[row][col]=1;
        dfs(row+1,col,n,m,vis,heights,heights[row][col]);
         dfs(row-1,col,n,m,vis,heights,heights[row][col]);
          dfs(row,col+1,n,m,vis,heights,heights[row][col]);
           dfs(row,col-1,n,m,vis,heights,heights[row][col]);
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>>pac(n,vector<int>(m,0));
        vector<vector<int>>alt(n,vector<int>(m,0));

        for(int i=0;i<n;i++)
        {
            dfs(i,0,n,m,pac,heights,heights[i][0]);
            dfs(i,m-1,n,m,alt,heights,heights[i][m-1]);
        }
        for(int i=0;i<m;i++)
        {
            dfs(0,i,n,m,pac,heights,heights[0][i]);
            dfs(n-1,i,n,m,alt,heights,heights[n-1][i]);
        }
           vector<vector<int>>ans;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(pac[i][j] && alt[i][j])
                {
                   ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};
