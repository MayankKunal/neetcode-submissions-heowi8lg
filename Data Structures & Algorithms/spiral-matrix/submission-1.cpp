class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        int row=matrix.size()-1;
        int col=matrix[0].size()-1;
        int r=0,c=0;
        int i,j;
        vector<int>ans;
    while(r<=row && c<=col)
    {
        i=r,j=c;
        while(j<=col)
        {
            ans.push_back(matrix[i][j++]);
        }
        r=r+1;
        i=r,j=col;
        while(i<=row)
        {
            ans.push_back(matrix[i++][j]);
        }
        col=col-1;
        i=row,j=col;
        if(r<=row)
        while(j>=c)
        {
             ans.push_back(matrix[i][j--]);
        }
        row=row-1;
        i=row,j=c;
        if(c<=col)
        while(i>=r)
        {
            ans.push_back(matrix[i--][j]);
        }
        c=c+1;
    }
  return ans;
    }
};
