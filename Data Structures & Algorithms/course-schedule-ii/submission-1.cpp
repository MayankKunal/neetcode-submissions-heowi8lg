class Solution {
     vector<int> khanAlgo(int n, vector<vector<int>>& prerequisites)
    {
         vector<int>inOrder(n,0);
         vector<int>ans;
        unordered_map<int,vector<int>>graph;
        for(auto pre:prerequisites)
        {
          int src=pre[1];
          int des=pre[0];
          graph[src].push_back(des);
          inOrder[des]++;
        }
        queue<int>q;
         vector<int>vis(n,0);
        for(int i=0;i<n;i++)
        {
            if(inOrder[i]==0)
            {
                q.push(i);
                vis[i]=1;
                ans.push_back(i);
            }
        }
       
        while(!q.empty())
        {
            auto node=q.front();
            q.pop();
            
            for(auto adjNode:graph[node])
            {
                inOrder[adjNode]--;
                if(inOrder[adjNode]==0 && !vis[adjNode])
                {
                    vis[adjNode]=1;
                    q.push(adjNode);
                    ans.push_back(adjNode);
                }
            }
        }
        
        for(auto x:inOrder)
        {
            if(x!=0) return {};
        }
        return ans;
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
         
         return khanAlgo(numCourses,prerequisites);
    }
};
