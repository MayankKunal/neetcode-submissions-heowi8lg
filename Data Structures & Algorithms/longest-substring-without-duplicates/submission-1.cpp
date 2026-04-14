class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        unordered_map<char,int>mp;
        int n=s.size();

       int left=0,right=0;
       int ans=0;
       while(right<n)
       {
            mp[s[right]]++;
            while(mp[s[right]]>1)
            {
                mp[s[left]]--;
                left++;
            }
            ans=max(ans,right-left+1);
            right++;
       }
       return ans;
    }
};
