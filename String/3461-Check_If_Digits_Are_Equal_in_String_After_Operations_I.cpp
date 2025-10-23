class Solution {
public:
    bool hasSameDigits(string s)
    {
        int i=0;
        string ans="";
        while(s.size()>2 && i<s.size()-1)
        {
            ans+=(s[i]+s[i+1])%10;
            i++;
            if(i==s.size()-1)
            {
                s=ans;
                i=0;
                ans="";
            }
        }
        return s.size()==2 and s[0]==s[1];
    }
};
