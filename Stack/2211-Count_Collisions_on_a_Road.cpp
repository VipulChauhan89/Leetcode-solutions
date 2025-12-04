class Solution {
public:
    int countCollisions(string directions)
    {
        stack<char> st;
        int ans=0;
        for(int i=0;i<directions.size();i++)
        {
            if(directions[i]=='R')
            {
                st.push('R');
            }
            else if(directions[i]=='L')
            {
                if(!st.empty() && st.top()=='R')
                {
                    ans+=2;
                    st.pop();
                    st.push('S');
                }
                else if(!st.empty() && st.top()=='S')
                {
                    ans+=1;
                }
            }
            else if(directions[i]=='S')
            {
                if(!st.empty() && st.top()=='R')
                {
                    ans+=1;
                    st.pop();st.push('S');
                }
                else
                {
                    st.push('S');
                }
            }
        }
        while(!st.empty())
        {
            if(st.top()=='S')
            {
                st.pop();
                while(!st.empty() && st.top()=='R')
                {
                    ans++;
                    st.pop();
                }
            }
            else
            {
                st.pop();
            }
        }
        return ans;
    }
};
