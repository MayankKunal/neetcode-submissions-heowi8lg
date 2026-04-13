class Solution {
    int help(int i,int j,int n,int m,string &s,string &t)
    {
        if(i==n) return (j==m);
        if(j==m) return 1;

        if(s[i]==t[j])
        {
            return help(i+1,j+1,n,m,s,t)+help(i+1,j,n,m,s,t);
        }
        return help(i+1,j,n,m,s,t);
    }
public:
    int numDistinct(string s, string t) {
        
        int n=s.size();
        int m=t.size();

        return help(0,0,n,m,s,t);
    }
};
