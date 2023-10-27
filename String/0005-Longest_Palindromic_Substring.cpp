class Solution {
public:
    string expandAroundCenter(string s,int l, int r)
    {
        while(l>=0 && r<s.length() && s[l]==s[r])
        {
            l--;
            r++;
        }
        return s.substr(l+1,r-l-1);
    }
    string longestPalindrome(string s) 
    {
        string ans="";
        for(int i=0;i<s.length();i++)
        {
            string o=expandAroundCenter(s,i,i),e=expandAroundCenter(s,i,i+1);
            if(o.length()>ans.length())
            {
                ans=o;
            }
            if(e.length()>ans.length())
            {
                ans=e;
            }
        }
        return ans;
    }
};
