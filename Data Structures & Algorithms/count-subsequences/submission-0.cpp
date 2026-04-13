class Solution {
    int help(int i,int n,string s,string temp,string t)
    {
        if(i==n)
        {
            if(temp==t) return 1;
            return 0;
        }

        return help(i+1,n,s,temp+s[i],t)+help(i+1,n,s,temp,t);

    }
public:
    int numDistinct(string s, string t) {
        
        int n=s.size();
        return help(0,n,s,"",t);
    }
};
