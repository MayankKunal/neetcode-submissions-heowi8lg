class Solution {
public:
    double myPow(double x, int n) {
        
        double ans=1;
        bool flag=false;
        if(n<0)
        {
      flag=true;
        }
        n=abs(n);
        while(n>0)
        {
            if(n%2==1)
            {
                ans*=x;
                n-=1;
            }
            else
            {
                x*=x;
              n/=2;
            }
        }
        if(!flag)
        return ans;
        else return (double)1/ans;
    }
};
