class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        unordered_map<int,vector<int>>graph;
         int n=numCourses;
        vector<int>inDegree(n,0);
        for(auto x:prerequisites)
        {
            graph[x[1]].push_back(x[0]);
            inDegree[x[0]]++;
        }
       
        queue<int>q;
        for(int i=0;i<n;i++)
        {
            if(inDegree[i]==0) q.push(i);
        }
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            for(auto adjNode:graph[node])
            {
                inDegree[adjNode]--;
                if(inDegree[adjNode]==0)
                {
                    q.push(adjNode);
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
