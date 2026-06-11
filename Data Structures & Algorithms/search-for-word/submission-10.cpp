class Solution {
    bool help(int i,int j,int n,int m,vector<vector<char>>& board,int k,int l,
    string &word,vector<vector<int>>&vis)
    {
         if(k==l) return true;
        if(i<0 || j<0 || i==n || j==m || board[i][j]!=word[k] || vis[i][j]) return false;
        
        vis[i][j]=1;
        bool res=help(i+1,j,n,m,board,k+1,l,word,vis)||
            help(i-1,j,n,m,board,k+1,l,word,vis)||
            help(i,j+1,n,m,board,k+1,l,word,vis)||
            help(i,j-1,n,m,board,k+1,l,word,vis);
            vis[i][j]=0;
        return res;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        
        int n=board.size();
        int m=board[0].size();
        int l=word.size();
        vector<vector<int>>vis(n+1,vector<int>(m+1,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(word[0]==board[i][j])
                {
                    if(help(i,j,n,m,board,0,l,word,vis))
                    return true;
                }
            }
        }
        return false;

    }
};
