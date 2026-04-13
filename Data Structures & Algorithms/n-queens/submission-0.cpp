class Solution {

    bool isPossible(vector<string>&board,int row,int col,int n)
    {
        int i=row,j=col;
        while(i>=0 && j>=0)
        {
            if(board[i--][j--]=='Q') return false;
        }
        i=row,j=col;
        while(i>=0 && j<n)
        {
            if(board[i--][j++]=='Q') return false;
        }
        i=row,j=col;
        while(i>=0)
        {
            if(board[i--][j]=='Q') return false;
        }
        return true;
    }


    void help(int row,int n,vector<string>board,vector<vector<string>>&ans)
    {
        if(row==n)
        {
            ans.push_back(board);
            return;
        }
        for(int col=0;col<n;col++)
        {
            if(isPossible(board,row,col,n))
            {
                board[row][col]='Q';
                help(row+1,n,board,ans);
                board[row][col]='.';
            }
        }

    }
public:

    vector<vector<string>> solveNQueens(int n) 
    {
        
        vector<string>board(n,string(n,'.'));
        
        vector<vector<string>>ans;
        
            help(0,n,board,ans);
        
        return ans;
    }
};
