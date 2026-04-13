class Solution {
  int help(int i,int j,int n,int m,int currVal,vector<vector<int>>&matrix)
  {
    if(i<0 ||j<0 ||i>=n || j>=m || matrix[i][j]<=currVal) return 0;
     
     int up=help(i-1,j,n,m,matrix[i][j],matrix);
     int left=help(i,j-1,n,m,matrix[i][j],matrix);
     int down=help(i+1,j,n,m,matrix[i][j],matrix);
     int right=help(i,j+1,n,m,matrix[i][j],matrix);

     return 1+max(up,max(left,max(down,right)));
  }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        
       int ans=1;
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<n;i++)
        {
           for(int j=0;j<m;j++)
           {
            ans=max(ans,help(i,j,n,m,-1,matrix));
           } 
        }

        return ans;
    }

};
