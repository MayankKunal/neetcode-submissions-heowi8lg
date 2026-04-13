class Solution {
    int help(int i,int j,int n,int m,string s,string p,vector<vector<int>>&dp)
    {
        if(i==n || j==m) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==p[j])
        {
            return dp[i][j]=1+help(i+1,j+1,n,m,s,p,dp);
        } 
        return dp[i][j]=max(help(i+1,j,n,m,s,p,dp),help(i,j+1,n,m,s,p,dp));
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return help(0,0,n,m,text1,text2,dp);
    }
};
