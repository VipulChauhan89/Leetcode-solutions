class Solution {
public:
    string robotWithString(string s) 
    {
        int n=s.length();
        vector<char> m(n);
        m[n-1]=s[n-1];
        for(int i=n-2;i>=0;i--)
        {
            m[i]=min(s[i],m[i+1]);
        }
        stack<char> st;
        string ans;
        for(int i=0;i<n;i++)
        {
            st.push(s[i]);
            while(!st.empty() && (i+1==n || st.top()<=m[i+1]))
            {
                ans+=st.top();
                st.pop();
            }
        }
        while(!st.empty())
        {
            ans+=st.top();
            st.top();
        }
        return ans;
    }
};
