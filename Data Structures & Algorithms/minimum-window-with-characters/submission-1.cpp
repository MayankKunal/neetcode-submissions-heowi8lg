class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.size();
        int l=0,r=0;
        unordered_map<char,int>mp1;
        unordered_map<char,int>mp2;
        for(auto x:t)
        {
            mp1[x]++;
        }
        string ans="";
        int have=0,count=mp1.size();
        while(r<n)
        {
            if(mp1.find(s[r])!=mp1.end())
            {
                mp2[s[r]]++;
               if(mp2[s[r]]==mp1[s[r]])
                    have++;
            }
           while(have==count)
           {
            if(ans=="" ||ans.size()>=(r-l+1))
               {
                ans=s.substr(l,r-l+1);
               }
               if(mp1.find(s[l])!=mp1.end())
               {
                mp2[s[l]]--;
                if(mp2[s[l]]<mp1[s[l]])
                    have--;
               }
               
               l++;
           }
           r++;
        }
        return ans;
    }
};
