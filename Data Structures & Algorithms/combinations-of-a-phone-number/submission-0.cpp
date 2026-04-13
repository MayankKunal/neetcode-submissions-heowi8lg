class Solution {
    void help(int i,int n,string digits,unordered_map<char,string>&mp,
    string temp,vector<string>&ans
    )
    {
    if(i==n)
    {
        ans.push_back(temp);
        return;
    }
      char curr=digits[i];
      for(auto x:mp[curr])
      {
        help(i+1,n,digits,mp,temp+x,ans);
      }
    }
public:
    vector<string> letterCombinations(string digits) {
        int n=digits.size();
        if(n==0) return {};
        unordered_map<char,string>mp;
        mp['2']="abc";
        mp['3']="def";
        mp['4']="ghi";
        mp['5']="jkl";
        mp['6']="mno";
        mp['7']="pqrs";
        mp['8']="tuv";
        mp['9']="wxyz";
        vector<string>ans;
        help(0,n,digits,mp,"",ans);
        return ans;
    }
};
