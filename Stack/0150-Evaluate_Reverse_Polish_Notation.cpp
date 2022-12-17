class Solution {
public:
    int evalRPN(vector<string>& tokens) 
    {
        long a,b;
        stack<int> st;
        for(auto i:tokens)
        {
            if(i=="+")
            {
                a=st.top();
                st.pop();
                b=st.top();
                st.pop();
                st.push(b+a);
            }
            else if(i=="-")
            {
                a=st.top();
                st.pop();
                b=st.top();
                st.pop();
                st.push(b-a);
            }
            else if(i=="*")
            {
                a=st.top();
                st.pop();
                b=st.top();
                st.pop();
                st.push(b*a);
            }
            else if(i=="/")
            {
                a=st.top();
                st.pop();
                b=st.top();
                st.pop();
                st.push(b/a);
            }
            else
            {
                st.push(stoi(i));
            }
        }
        return st.top();
    }
};
