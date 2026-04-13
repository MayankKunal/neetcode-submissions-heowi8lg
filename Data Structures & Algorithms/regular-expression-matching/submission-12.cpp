class Solution {
    bool help(int i,int j,int n,int m,string &s,string &p)
    {
    
        if(j==m) return (i==n);

   bool match=(i<n && (s[i]==p[j] || p[j]=='.'));
        if((j+1)<m && p[j+1]=='*')
        {

            return help(i,j+2,n,m,s,p)||(match && help(i+1,j,n,m,s,p));
        }
        if(match) return help(i+1,j+1,n,m,s,p);
        return false;
    }
public:
    bool isMatch(string s, string p) {
        
        int n=s.size();
        int m=p.size();


        return help(0,0,n,m,s,p);
    }
};
