class Solution {
    string oddLen(string &s,int i)
    {
        int n=s.size();
        int l=i,r=i;
        int idx=i,len=1;
        while(l>=0 && r<n && s[l]==s[r])
        {
            idx=l;
            len=r-l+1;
                l--;
                r++;
        }
        return s.substr(idx,len);
    }
    string evenLen(string &s,int l,int e)
    {
        int n=s.size();
        int idx=l,len=2;
        while(l>=0 && e<n && s[l]==s[e])
        {
             idx=l;
             len=e-l+1;
             l--;
             e++;
        }
        return s.substr(idx,len);
    }
public:
    string longestPalindrome(string s) {
        
        int n=s.size();
        string ans="";
        for(int i=0;i<n;i++)
        {
            string s1=oddLen(s,i);
            string s2="";
            if((i+1)<n && s[i]==s[i+1])
            s2=evenLen(s,i,i+1);

            if(s1.size()>ans.size() || s2.size()>ans.size())
            {
                if(s1.size()>s2.size())
                {
                    ans=s1;
                }
                else ans=s2;
            }
        }
        return ans;
    }
};
