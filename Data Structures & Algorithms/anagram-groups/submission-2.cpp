class Solution {
    bool isAnagram(string &a,string &b)
    {
        if(a.size()!=b.size()) return false;
        vector<int>mp(26,0);
       int n=a.size();
        for(int i=0;i<n;i++)
        {
            mp[a[i]-'a']++;
            mp[b[i]-'a']--;
        }

        for(int i=0;i<26;i++)
        {
            if(mp[i]!=0) return false;
        }
        return true;
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        int n=strs.size();
        vector<int>counted(n,0);
        vector<vector<string>>ans;
        for(int i=0;i<n;i++)
        {
            if(counted[i]!=0) continue;
              vector<string>temp;
              temp.push_back(strs[i]);
            for(int j=i+1;j<n;j++)
            {
                if(isAnagram(strs[i],strs[j]))
                {
                    temp.push_back(strs[j]);
                    counted[j]++;
                }  
            }
            ans.push_back(temp);
        }

        return ans;
    }
};
