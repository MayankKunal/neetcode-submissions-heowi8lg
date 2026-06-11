class Solution {
    void help(int i,int c,int n,string temp,vector<string>&ans)
    {
        if(i==n && c==n)
        {
           
            ans.push_back(temp);
            return;
        }

        if(i<n) help(i+1,c,n,temp+"(",ans);
        if(c<n && c<i) help(i,c+1,n,temp+")",ans);
    }
public:
    vector<string> generateParenthesis(int n) {
        

        vector<string>ans;
        help(0,0,n,"",ans);
        return ans;
    }
};
