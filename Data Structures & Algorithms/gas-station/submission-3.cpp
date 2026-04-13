class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int n=gas.size();
        vector<int>diff(n,0);
        int sum=0;
        for(int i=0;i<n;i++)
        {
            diff[i]=gas[i]-cost[i];
            sum+=gas[i]-cost[i];
        }
        if(sum<0) return -1;
        int res=-1;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            ans+=diff[i];
            if(ans>=0 && res==-1)
            {
                res=i;
            }
            if(ans<0)
            {
                ans=0;
                res=-1;
            } 
        
        }
        return res;
    }
};
