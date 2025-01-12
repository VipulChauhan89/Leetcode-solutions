class Solution {
public:
    bool canBeValid(string s,string locked) 
    {
        int n=s.length();
        if(n&1)
        {
            return 0;
        }    
        int mn=0,mx=0;
        for(int i=0;i<n;i++)
        {
            bool op=(s[i]=='('),wd=(locked[i]=='0');
            mn+=(!op | wd)?-1:1;
            mx+=(op | wd)?1:-1;
            if(mx<0)
            {
                return 0;
            }
            mn=max(mn,0);
        }
        return mn==0;
    }
};
