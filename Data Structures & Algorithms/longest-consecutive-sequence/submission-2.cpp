class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        set<int>st;
        for(auto x:nums)
        {
            st.insert(x);
        }
        int prev=INT_MIN;
        int count=0,maxCount=0;
        for(auto &x:st)
        {
               if(prev==INT_MIN || prev+1==x)
               {
                prev=x;
                count++;
               }
               else
               {
                prev=x;
                maxCount=max(count,maxCount);
                count=1;
               }
        }
        maxCount=max(count,maxCount);
        return maxCount;
    }
};
