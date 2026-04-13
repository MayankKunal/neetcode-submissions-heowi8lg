class Solution {
    bool match(unordered_map<char,int>&mp, string t)
    {
        unordered_map<char,int>temp=mp;
        for(int i=0;i<t.size();i++)
        {
            if(temp.find(t[i])==temp.end()) return false;
            temp[t[i]]--;
            if(temp[t[i]]==0) temp.erase(t[i]);
        }
        return true;
    }
public:
    string minWindow(string s, string t) {

       int n=s.size();
       int l=0,r=0;
       string ans="";
       unordered_map<char,int>mp;
       while(r<n)
       {
           mp[s[r]]++;
           while(match(mp,t))
           {
             mp[s[l]]--;
             if(mp[s[l]]==0) mp.erase(s[l]);
             ans=s.substr(l,r-l+1);
             l++;
             
           }
           r++;
       }   
       return ans; 
    }
};
