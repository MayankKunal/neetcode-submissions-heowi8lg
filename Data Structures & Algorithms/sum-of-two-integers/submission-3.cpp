class Solution {
public:
    int getSum(int a, int b) {
        
        int ans=0;
        int carry=0;
        for(int i=0;i<32;i++)
        {
            int aBit=((a>>i)&1);
            int bBit=((b>>i)&1);
           
           int digit=aBit^bBit^carry;
           if(digit)
           {
            ans|=(1<<i);
           }
           if((aBit+bBit+carry)>1) carry=1;
           else carry=0;
        }
        return ans;
    }
};
