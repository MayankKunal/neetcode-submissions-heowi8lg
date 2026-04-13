class Solution {
    int numberOfBits(int n)
    {
        int count=0;
        while(n>0)
        {
            int d=n&1;
            n=n>>1;
           count+=d;
        }
        return count;
    }
public:
    vector<int> countBits(int n) {
        vector<int>ans;
        for(int i=0;i<=n;i++)
        {
            ans.push_back(numberOfBits(i));
        }
        return ans;
    }
};
