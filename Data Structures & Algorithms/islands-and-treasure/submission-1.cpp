class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();

        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>>pq;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==0)
                {
                    pq.push({0,{i,j}});
                }
            }
        }

        int dr[4]={-1,0,1,0};
        int dc[4]={0,1,0,-1};
        while(!pq.empty())
        {
            auto it=pq.top();
            pq.pop();
            int dis=it.first;
            int r=it.second.first;
            int c=it.second.second;
         for(int i=0;i<4;i++)
         {
            int row=r+dr[i];
            int col=c+dc[i];
            if(row<0 || row>=n || col<0 || col>=m || grid[row][col]==-1) continue;
            if(grid[row][col]>(dis+1))
            {
                grid[row][col]=dis+1;
                pq.push({dis+1,{row,col}});
            }
         }
        }
    }
};
