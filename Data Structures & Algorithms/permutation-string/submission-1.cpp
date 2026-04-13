class Solution {
    bool  match(string s1,string s2)
    {
        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());
        return s1==s2;
    }
public:
    bool checkInclusion(string s1, string s2) {
        
        int k=s1.size();
        int n=s2.size();
        
        for(int i=0;i<n-k+1;i++)
        {
            string s=s2.substr(i,k);
            if(match(s1,s)) return true;
        }
        return false;
    }
};
