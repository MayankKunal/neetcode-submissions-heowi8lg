class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<int>ans(n+1,INT_MAX);
        vector<pair<int,int>>Adj[n+1];
        for(auto time:times)
        {
            Adj[time[0]].push_back({time[1],time[2]});
        }
            ans[k]=0;
            queue<pair<int,int>>q;
            q.push({k,0});
            while(!q.empty())
            {
                auto it=q.front();
                q.pop();
                int node=it.first;
                int d=it.second;
                for(auto  x:Adj[node])
                {
                    int adjNode=x.first;
                    int dis=x.second;
                    if(ans[adjNode]>(d+dis))
                    {
                        ans[adjNode]=d+dis;
                      q.push({adjNode,d+dis});
                    }
                }
            }   
            // ans[0]=0;
            int res=0;
            for(int i=1;i<=n;i++)
            {  
                res=max(res,ans[i]);
            }
            if(res==INT_MAX) return -1;
            return res;
    }
};
