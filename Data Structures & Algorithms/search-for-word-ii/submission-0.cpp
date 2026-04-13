class Solution {
    bool help(int i,int j,int k,int n,int m,int p,vector<vector<char>>& board,string &word,
    vector<vector<int>>&vis)
    {
        if(k==p) return true;
     if(i<0 || i==n || j<0 ||j==m ||vis[i][j]||board[i][j]!=word[k]) return false;
         
         vis[i][j]=1;
         bool res=help(i+1,j,k+1,n,m,p,board,word,vis)||
         help(i-1,j,k+1,n,m,p,board,word,vis)||help(i,j+1,k+1,n,m,p,board,word,vis)||
         help(i,j-1,k+1,n,m,p,board,word,vis);
         vis[i][j]=0;
         return res;
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        
        int k=words.size();
        int n=board.size();
        int m=board[0].size();
        vector<string>ans;
        for(int i=0;i<k;i++)
        {
            string word=words[i];
            char initial=word[0];
            int p=word.size();
            vector<vector<int>>vis(n,vector<int>(m,0));
            bool flag=false;
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                {
                    if(board[i][j]==initial)
                    {
                        if(help(i,j,0,n,m,p,board,word,vis))
                        {
                            ans.push_back(word);
                            flag=true;
                            break;
                        }
                    }
                }
                if(flag) break;
            }
        }
        return ans;
    }
};
