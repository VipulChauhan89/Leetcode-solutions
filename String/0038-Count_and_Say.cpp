class Solution {
public:
    string solve(string s,int n)
    {
        if(n==0)
        {
            return s;
        }
        string ans="";
        int sn=s.length(),count=1;
        char current=s[0];
        for(int i=1;i<sn;i++)
        {
            if(s[i]==current)
            {
                count++;
            }
            else
            {
                ans+=to_string(count);
                ans+=current;
                count=1;
                current=s[i];
            }
        }
        ans+=to_string(count);
        ans+=current;
        return solve(ans,n-1);
    }
    string countAndSay(int n) 
    {
        return solve("1",n-1);
    }
};
