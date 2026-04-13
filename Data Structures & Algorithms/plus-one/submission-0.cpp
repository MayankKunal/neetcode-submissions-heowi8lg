class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
       
        reverse(digits.begin(),digits.end());
        int carry=1;
        int n=digits.size();
        for(int i=0;i<n;i++)
        {
          int val=digits[i]+carry;
          digits[i]=val%10;
          carry=val/10;
        }
        if(carry)
        {
            digits.push_back(1);
        }
        reverse(digits.begin(),digits.end());
        return digits;
    }
};
