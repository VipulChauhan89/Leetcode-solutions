class Solution {
public:
    string minRemoveToMakeValid(string s) 
    {
        int l=0,r=0;
        stack<char> st;
        for(auto i:s)
        {
            if(i=='(')
            {
                l++;
            }
            else if(i==')')
            {
                r++;
            }
            if(r>l)
            {
                r--;
                continue;
            }
            else
            {
                st.push(i);
            }
        }
        string ans="";
        while(!st.empty())
        {
            char c=st.top();
            st.pop();
            if(l>r &&c=='(')
            {
                l--;
            }
            else 
            {
                ans+=c;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
