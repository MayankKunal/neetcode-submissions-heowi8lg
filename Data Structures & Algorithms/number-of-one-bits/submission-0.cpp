class Solution {
public:
    int hammingWeight(uint32_t n) {
           int count=0;
           while(n>0)
           {
            int d=n&1;
             count+=d;
             n=n>>1;
           }
           return count;
    }
};
