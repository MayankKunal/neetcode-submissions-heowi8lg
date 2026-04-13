class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        // int land=2147483647;
        queue<pair<int,pair<int,int>>>q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==0)
                {
                    q.push({0,{i,j}});
                }
            }
        }
int drow[4]={0,-1,0,1};
int dcol[4]={-1,0,1,0};
        while(!q.empty())
        {
            auto it=q.front();
            q.pop();
            int dis=it.first;
            int row=it.second.first;
            int col=it.second.second;
             
             for(int i=0;i<4;i++)
             {
                int nrow=row+drow[i];
                int ncol=col+dcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]!=0 && grid[nrow][ncol]!=-1)
                {
                     if(grid[nrow][ncol]>dis+1)
                     {
                        grid[nrow][ncol]=dis+1;
                        q.push({dis+1,{nrow,ncol}});
                     }
                }
             }
        }
    }
};
