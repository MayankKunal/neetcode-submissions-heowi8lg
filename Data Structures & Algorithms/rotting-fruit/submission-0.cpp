class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        int fresh=0;
        queue<pair<int,pair<int,int>>>q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({0,{i,j}});
                }
                if(grid[i][j]==1) fresh++;
            }
        }
        int maxTime=0;
        int drow[4]={0,-1,0,1};
        int dcol[4]={-1,0,1,0};
        while(!q.empty())
        {
            auto it=q.front();
            q.pop();
            int time=it.first;
            int row=it.second.first;
            int col=it.second.second;
            maxTime=max(maxTime,time);
            for(int i=0;i<4;i++)
            {
                int nrow=row+drow[i];
               int  ncol=col+dcol[i];
                if(nrow<n && nrow>=0 && ncol>=0 && ncol<m && grid[nrow][ncol]==1)
                {
                    fresh--;
                    grid[nrow][ncol]=2;
                    q.push({time+1,{nrow,ncol}});
                }
            }
        }
        if(fresh==0) return maxTime;
        return -1;
    }
};
