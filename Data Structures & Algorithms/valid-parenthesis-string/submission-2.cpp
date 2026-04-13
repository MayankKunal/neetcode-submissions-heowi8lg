class Solution {
public:
    bool checkValidString(string s) {
        
        stack<char>st;
        stack<char>st2;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
            {
                st.push(i);
            }
            else if(s[i]==')')
            {
                if(st.empty() && st2.empty()) return false;
                else if(!st.empty()) st.pop();
                else st2.pop();
            }
            else if(s[i]=='*')
            {
                st2.push(i);
            }
        }

        while(!st.empty() && !st2.empty())
        {
            if(st.top()>st2.top())
            {
                return false;
            }
            st.pop();
            st2.pop();
        }
        if(st2.empty() && !st.empty()) return false;
        return true;

       
        



    }
};
