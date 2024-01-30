class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<int> st;
        for(auto &i:tokens)
        {
            if(i!="+" && i!="-" && i!="*" && i!="/")
            {
                st.push(stoi(i));
            }
            else
            {
                int a=st.top();
                st.pop();
                int b=st.top();
                st.pop();
                int ans=0;
                if(i=="+")
                {
                    ans=a+b;
                }
                else if(i=="-")
                {
                    ans=b-a;
                }
                else if(i=="*")
                {
                    ans=a*b;
                }
                else
                {
                    ans=b/a;
                }
                st.push(ans);
            }
        }
        return st.top();
    }
};
