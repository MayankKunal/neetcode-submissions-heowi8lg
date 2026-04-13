class Solution {
    void help(int i,int j,int n,int m,vector<vector<char>>&board)
    {
        if(i<0 || i==n || j<0 || j==m || board[i][j]!='O') return;

        board[i][j]='o';
        help(i-1,j,n,m,board);
        help(i+1,j,n,m,board);
        help(i,j+1,n,m,board);
        help(i,j-1,n,m,board);
    }
public:
    void solve(vector<vector<char>>& board) {


       int n=board.size();
       int m=board[0].size();

       for(int i=0;i<n;i++)
       {
        for(int j=0;j<m;j++)
        {
            if(board[i][j]=='O' && (i==0 || j==0 || i==n-1 || j==m-1))
            {
                help(i,j,n,m,board);
            }
        }
       } 

       for(int i=0;i<n;i++)
       {
        for(int j=0;j<m;j++)
        {
            if(board[i][j]=='o')
            board[i][j]='O';
            else board[i][j]='X';
        }
       }
       
    }
};
