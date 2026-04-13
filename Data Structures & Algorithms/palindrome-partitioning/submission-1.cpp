class Solution {
    bool isPalindrome(string s)
    {
        int l=0,r=s.size()-1;
        while(l<r)
        {
            if(s[l++]!=s[r--]) return false;
        }
        return true;
    }
    void help(int i,int n,string s,vector<string>temp,vector<vector<string>>&ans)
    {
        if(i==n)
        {
            ans.push_back(temp);
            return;
        }
        for(int idx=i;idx<n;idx++)
        {

             string s1=s.substr(i,idx-i+1);
             if(isPalindrome(s1))
             {
             temp.push_back(s1);
             help(idx+1,n,s,temp,ans);
               temp.pop_back();
             }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        
        int n=s.size();
        vector<vector<string>>ans;
        vector<string>temp;
        help(0,n,s,temp,ans);
        return ans;
    }
};
