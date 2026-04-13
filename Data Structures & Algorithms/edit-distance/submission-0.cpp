class Solution {
    int help(int i,int j,int n,int m,string s1,string s2,vector<vector<int>>&dp)
    {
        if(i==n) return m-j;
        if(j==m) return n-i;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i]==s2[j])
         return dp[i][j]=help(i+1,j+1,n,m,s1,s2,dp);
        else
         return dp[i][j]=1+min(help(i+1,j,n,m,s1,s2,dp),min(help(i,j+1,n,m,s1,s2,dp),
         help(i+1,j+1,n,m,s1,s2,dp)));
    }
public:
    int minDistance(string word1, string word2) {
        
        int n=word1.size();
        int m=word2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));

        return help(0,0,n,m,word1,word2,dp);

    }
};
