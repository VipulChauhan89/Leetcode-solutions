class Solution {
public:
    string reverseParentheses(string s) 
    {
        stack<char> st;
        for(int i=0;i<s.length();i++)
        {
            char c=s[i];
            if(c==')')
            {
                string reverse="";
                while(!st.empty() && st.top()!='(')
                {
                    reverse+=st.top();
                    st.pop();
                }
                if(!st.empty())
                {
                    st.pop();
                }
                for(int j=0;j<reverse.length();j++)
                {
                    st.push(reverse[j]);
                }
            }
            else
            {
                st.push(c);
            }
        }  
        string ans="";
        while(!st.empty())
        {
            ans=st.top()+ans;
            st.pop();
        } 
        return ans; 
    }
};
