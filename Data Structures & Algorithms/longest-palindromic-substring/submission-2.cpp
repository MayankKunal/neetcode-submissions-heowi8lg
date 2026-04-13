class Solution {
    bool isPalindrome(string &s)
    {
        int n=s.size();
        int l=0,r=n-1;
        while(l<r)
        {
            if(s[l]!=s[r]) return false;
            l++;
            r--;
        }
        return true;
    }
public:
    string longestPalindrome(string s) {
        
        int n=s.size();
      string ans="";
        for(int i=0;i<n;i++)
        {
            string temp="";
            for(int j=i;j<n;j++)
            {
              temp+=s[j];
              if(isPalindrome(temp) && temp.size()>ans.size())
            {
                ans=temp;
            }
            }
        }
        return ans;
    }
};
