class Solution {
    bool help(int i,int j,int n,int m,int k,vector<vector<char>>&board,
    string word,vector<vector<int>>&vis)
    {
         if(k==word.size()) return true;
        if(i<0||j<0 ||i>=n || j>=m || board[i][j]!=word[k] ||vis[i][j]) return false;
            vis[i][j]=1;
        bool res=help(i+1,j,n,m,k+1,board,word,vis)||
        help(i,j+1,n,m,k+1,board,word,vis)||
                help(i-1,j,n,m,k+1,board,word,vis)
                ||help(i,j-1,n,m,k+1,board,word,vis);
        vis[i][j]=0;
        return res;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        
        int n=board.size();
        int m=board[0].size();
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            { vector<vector<int>>vis(n+1,vector<int>(m+1,0));
                if(board[i][j]==word[0])
                {
                     
                    if(help(i,j,n,m,0,board,word,vis)) return true;
                }
            }
        }
        return false;
    }
};
