class Solution {
public:
    int getSum(int a, int b) {
        
        int sum=0;
      int carry=0;
      for(int i=0;i<32;i++)
      {
          int aBit=(a>>i)&1;
          int bBit=(b>>i)&1;
          
          if(aBit&&bBit&&carry)
          {
            sum|=(1<<i);
            carry=1;
          }
          else if((aBit&&bBit) || (aBit&&carry) || (bBit&&carry))
          {
            carry=1;
          }
          else if( aBit || bBit || carry)
          {
          sum|=(1<<i);
          carry=0;
          }
          
      }

      return sum;
    }
};
