class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        vector<int>adj[n];
        vector<int>inDegree(n);
        // vector<int>outDegree(n);
        for(auto x:prerequisites)
        {
            adj[x[1]].push_back(x[0]);
            inDegree[x[0]]++;
            
        }
        queue<int>q;
        for(int i=0;i<n;i++)
        {
            if(inDegree[i]==0)
            {
                q.push(i);
            }
        }
        vector<int>ans;
        while(!q.empty())
        {
            auto it=q.front();
            ans.push_back(it);
            q.pop();
            for(auto x:adj[it])
            {
                inDegree[x]--;
                if(inDegree[x]==0)
                {
                    q.push(x);
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            if(inDegree[i]!=0) return {};
        }
        return ans;
    }
};
