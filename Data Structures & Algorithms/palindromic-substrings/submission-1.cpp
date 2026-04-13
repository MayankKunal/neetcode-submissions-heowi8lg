class Solution {
    int oddLen(string &s,int i)
    {
        int n=s.size();
        int l=i,r=i;
        int count=0;
        while(l>=0 && r<n && s[l]==s[r])
        {
            count++;
            l--;
            r++;
        }
        return count;
    }
    int evenLen(string &s,int l,int r)
    {
        int n=s.size();
        int count=0;
        while(l>=0 && r<n && s[l]==s[r])
        {
            count++;
            l--;
            r++;
        }
        return count;
    }
public:
    int countSubstrings(string s) {
        
        int n=s.size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            ans+=oddLen(s,i);
            if((i+1)<n && s[i]==s[i+1])
            {
                ans+=evenLen(s,i,i+1);
            }
        }

        return ans;
    }
};
