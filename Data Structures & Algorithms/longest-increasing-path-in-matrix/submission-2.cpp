class Solution {
    int help(int i,int j,int prev,int n,int m,vector<vector<int>>&matrix)
    {
        if(i>=n || i<0 || j>=m || j<0 || matrix[i][j]<=prev) return 0;
         
         return 1+max(help(i+1,j,matrix[i][j],n,m,matrix),
         max(help(i-1,j,matrix[i][j],n,m,matrix),max(help(i,j+1,matrix[i][j],n,m,matrix),
         help(i,j-1,matrix[i][j],n,m,matrix))));

    }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        
  int n=matrix.size();
  int m=matrix[0].size();
      int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
            ans=max(ans,help(i,j,-1,n,m,matrix));       
            }
        }
        return ans;
    }
};
