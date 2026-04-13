class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        int n=numCourses;
        vector<int>adj[n];
        vector<int>inDegree(n);
        // vector<int>outDegree(n);
        for(auto x:prerequisites)
        {
            adj[x[0]].push_back(x[1]);
            inDegree[x[1]]++;
            // outDegree[x[0]]++;
        }
        queue<int>q;
        for(int i=0;i<n;i++)
        {
            if(inDegree[i]==0)
            {
                q.push(i);
            }
        }
        while(!q.empty())
        {
            auto it=q.front();
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
            if(inDegree[i]!=0) return false;
        }
        return true;
    }
};
