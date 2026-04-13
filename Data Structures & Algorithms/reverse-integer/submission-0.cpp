class Solution {
public:
    int reverse(int x) {
        int sign=1;
        if(x<0) sign=-1;
        x=abs(x);
        long long ans=0;
        while(x>0)
        {
           ans=ans*10+(x%10);
           x/=10;
        }
        if(ans>INT_MAX) return 0;
        return sign*ans;
    }
};
