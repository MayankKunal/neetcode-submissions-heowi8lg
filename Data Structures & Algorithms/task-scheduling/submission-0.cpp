class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        // int n=tasks.size();
        unordered_map<char,int>mp;
        for(char &task:tasks)
        {
            mp[task]++;
        }
        priority_queue<int>pq;
        queue<pair<int,int>>q;
        for(auto x:mp)
        {
            pq.push(x.second);
        }
        int time=0;
        while(!pq.empty() || !q.empty())
        {
            time++;
            if(!pq.empty())
            {
            int task=pq.top();
            pq.pop();
            task--;
            if(task!=0)
            q.push({task,time+n});
            }
            if(!q.empty())
            {
            if(q.front().second==time)
            {
                    pq.push(q.front().first);
                    q.pop();
            }
            }
        }
        return time;

    }
};
