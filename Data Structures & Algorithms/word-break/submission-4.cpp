class Solution {
    bool help(int i,int n,string s,unordered_set<string>&st,vector<int>&dp)
    {
        if(i==n) return true;
       if(dp[i]!=-1) return dp[i];
        for(int idx=1;idx<(n-i+1);idx++)
        {
            string temp=s.substr(i,idx);
            if(st.find(temp)!=st.end())
            {
                if(help(i+idx,n,s,st,dp)) return dp[i]=true;
            }
        }
        return dp[i]=false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
        unordered_set<string>st;
        for(string s:wordDict)
        {
            st.insert(s);
        }
        
          int n=s.size();
          vector<int>dp(n+1,-1);
        return help(0,n,s,st,dp);
    }
};
