class Solution {
    int help(int i,int j,int n,int m,string &s,string &t)
    {
        if(i==n) return j==m;
      int ans=0;
      int skip=help(i+1,j,n,m,s,t);
      int take=0;
        if(s[i]==t[j])
        {
            take=help(i+1,j+1,n,m,s,t);
        }
        return ans=(skip+take);
    }
public:
    int numDistinct(string s, string t) {
        
        int n=s.size();
        int m=t.size();

        return help(0,0,n,m,s,t);
    }
};
