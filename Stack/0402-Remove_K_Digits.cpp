class Solution {
public:
    string removeKdigits(string num,int k) 
    {
        stack<char> st;
        for(auto i:num)
        {
            while(!st.empty() && k>0 && st.top()>i)
            {
                st.pop();
                k--;
            }
            st.push(i);
        }    
        while(k>0 && !st.empty())
        {
            st.pop();
            k--;
        }
        string ans="";
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        auto p=ans.find_first_not_of('0');
        ans=(p==string::npos)?"0":ans.substr(p);
        return ans;
    }
};
