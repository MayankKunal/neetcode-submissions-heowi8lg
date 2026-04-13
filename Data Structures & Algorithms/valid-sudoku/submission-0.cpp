class Solution {
    bool isValid(int row,int col,int n,int m,char val,vector<vector<char>>&board)
    {
        for(int i=0;i<m;i++)
        {
           if(i!=col) if(board[row][i]==val) return false;
        }
        for(int i=0;i<n;i++)
        {
            if(i!=row) if(board[i][col]==val) return false;
        }

        int colShift=col/3;
        int rowShift=row/3;
           for(int i=rowShift*3;i<(rowShift+1)*3;i++)
           {
            for(int j=colShift*3;j<(colShift+1)*3;j++)
            {
                if(i!=row && j!=col && board[i][j]==val) return false;
            }
           }
           return true;

    }
    bool help(int n,int m,vector<vector<char>>&board)
    {

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]!='.')
                {
                    char val=board[i][j];
                    if(!isValid(i,j,n,m,val,board)) return false;
                }
            }
        }
        return true;
    }
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        int n=board.size();
        int m=board[0].size();
        return help(n,m,board);
    }
};
