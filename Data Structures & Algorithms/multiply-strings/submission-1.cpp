class Solution {
    long long strI(string s)
    {
        long long ans=0;
        for(int i=0;i<s.size();i++)
        {
            ans=ans*10+(s[i]-'0');
        }
        return ans;
    }
public:
    string multiply(string num1, string num2) {
        
        long long i1=strI(num1);
        long long i2=strI(num2);
        
        return to_string(i1*i2);
    }
};
