class Solution {
     bool isPalindrome(string s)
    {
        int n=s.size();
        int l=0,r=n-1;
        while(l<r)
        {
            if(s[l++]!=s[r--])
            return false;
        }
        return true;
    }
public:
    int countSubstrings(string s) {
        
        int n=s.size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            string temp="";
            for(int j=i;j<n;j++)
            {
                 temp+=s[j];
                 if(isPalindrome(temp))
                 {
                    ans++;
                 }
            }
        }
        return ans;
    }
};
