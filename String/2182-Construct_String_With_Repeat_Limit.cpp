class Solution {
public:
    string repeatLimitedString(string s,int repeatLimit) 
    {
        sort(s.rbegin(),s.rend());
        string ans="";
        int f=1,p=0;
        for(int i=0;i<s.length();i++)
        {
            if(!ans.empty() && ans.back()==s[i])
            {
                if(f<repeatLimit)
                {
                    ans+=s[i];
                    f++;
                }
                else
                {
                    p=max(p,i+1);
                    while(p<s.size() && s[p]==s[i])
                    {
                        p++;
                    }
                    if(p<s.size())
                    {
                        ans+=s[p];
                        swap(s[i],s[p]);
                        f=1;
                    }
                    else
                    {
                        break;
                    }
                }
            }
            else
            {
                ans+=s[i];
                f=1;
            }
        }
        return ans;
    }
};
