class Solution {
    int help(vector<int>&piles,int t)
    {
        int hours=0;
        for(int x:piles)
        {
            if(x%t==0)
            {
                hours+=x/t;
            }
            else
            {
                hours+=(x/t)+1;
            }
        }
        cout<<t<<" "<<hours<<"\n";
        return hours;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int l=1,r=-1;
        for(int x:piles)
        {
            r=max(r,x);
           
        }
        int ans=-1;
        while(l<=r)
        {
            int mid=(l+r)/2;

            int hours=help(piles,mid);
            if(hours>h)
            {
               l=mid+1;
            }
            else
            {
                ans=mid;
                  r=mid-1;
            }
        }
        return ans;
    }
};
