class Solution {
    bool help(int i,int j,int k,int n,int m,int o,string &s1,string &s2,string &s3,vector<vector<vector<int>>>&dp)
    {
        if(k==o) return (i==n)&&(j==m);
         
         if(dp[i][j][k]!=-1) return dp[i][j][k];
         bool ans=false;
        if(s3[k]==s1[i] || s3[k]==s2[j])
        {
            if( i<n && s3[k]!=s2[j])
             ans=help(i+1,j,k+1,n,m,o,s1,s2,s3,dp);
            else if( j<m && s3[k]!=s1[i])
           ans=help(i,j+1,k+1,n,m,o,s1,s2,s3,dp);
           else
               if(i<n && j<m)
            ans=help(i+1,j,k+1,n,m,o,s1,s2,s3,dp)||help(i,j+1,k+1,n,m,o,s1,s2,s3,dp);
        }
        return dp[i][j][k]=ans;
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        
        int n=s1.size();
        int m=s2.size();
        int o=s3.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(m+1,vector<int>(o+1,-1)));
        return help(0,0,0,n,m,o,s1,s2,s3,dp);
    }
};
