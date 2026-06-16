class Solution {
public:
    string processStr(string s)
    {
        string ans;
        int n=s.length();
        for(int i=0;i<n;i++)
        {
            char ch=s[i];
            if(ch=='*')
            {
                if(ans.length()!=0)
                {
                    ans.pop_back();
                }
            } 
            else if(ch=='#')
            {
                ans+=ans;
            } 
            else if(ch=='%')
            {
                reverse(ans.begin(),ans.end());
            } 
            else if(ch>='a' && ch<='z')
            {
                ans.push_back(ch);
            }
        }
        return ans;
    }
};
