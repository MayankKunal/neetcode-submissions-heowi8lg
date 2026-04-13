class Solution {
public:
    void solve(vector<vector<char>>& board) {
       int  n=board.size();
       int m=board[0].size();
       queue<pair<int,int>>q;
       for(int i=0;i<n;i++)
       {
        for(int j=0;j<m;j++)
        {
            if(board[i][j]=='O' && (i==0 || j==0 || i==n-1||j==m-1) )
            {
                q.push({i,j});
                board[i][j]='V';
            }
        }
       }
       int drow[4]={0,-1,0,1};
       int dcol[4]={-1,0,1,0};
       while(!q.empty())
       {
              auto it=q.front();
              q.pop();
              int row=it.first;
              int col=it.second;
              for(int i=0;i<4;i++)
              {
                int nrow=row+drow[i];
                int ncol=col+dcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && board[nrow][ncol]=='O')
                {
                    q.push({nrow,ncol});
                    board[nrow][ncol]='V';
                }
              }
       }

       for(int i=0;i<n;i++)
       {
        for(int j=0;j<m;j++)
        {
            if(board[i][j]=='O') board[i][j]='X';
        }
       }
       for(int i=0;i<n;i++)
       {
        for(int j=0;j<m;j++)
        {
            if(board[i][j]=='V') board[i][j]='O';
        }
       }
    }
};
