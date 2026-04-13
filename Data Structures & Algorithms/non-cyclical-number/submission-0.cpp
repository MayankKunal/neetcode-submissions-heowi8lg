class Solution {
    int help(int n)
    {
        int sum=0;
        while(n>0)
        {
         int d=n%10;
         n/=10;
         sum+=pow(d,2);
        }
        return sum;
    }
public:
    bool isHappy(int n) {
        
        unordered_set<int>st;
        while(st.find(n)==st.end())
        {
            st.insert(n);
            if(n==1) return true;
            n=help(n);
        }
        return false;
    }
};
