class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        
        unordered_map<char,int>inDegree;
      unordered_map<char,vector<char>>adj;
        int n=words.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<words[i].size();j++)
            {
                if(inDegree.find(words[i][j])==inDegree.end())
                {
                    inDegree[words[i][j]]=0;
                }
            }
        }

        for(int i=0;i<n-1;i++)
        {
            string word1=words[i];
            string word2=words[i+1];
            bool diff=false;
            for(int j=0;j<min(word1.size(),word2.size());j++)
            {
                if(word1[j]!=word2[j])
                {
                    diff=true;
                    inDegree[word2[j]]++;
                    adj[word1[j]].push_back(word2[j]);
                    break;
                } 
            }
            if(!diff  && word1.size()>word2.size()) return ""; 

        }
        string ans="";
        queue<char>q;
   for(auto &x:inDegree)
   {
    if(x.second==0)
    {
        q.push(x.first);
        // ans+=x.first;
    }
   }
// if(q.size()>1) return ans;
   while(!q.empty())
   {
    auto node=q.front();
    q.pop();
     ans+=node;
     for(auto adjNode:adj[node])
     {
        inDegree[adjNode]--;
        if(inDegree[adjNode]==0)
        {
            q.push(adjNode);
        }
     }
   }
  return ans.size()==inDegree.size()?ans:"";
    }
};
