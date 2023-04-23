class Solution {
public:
    int dp[100001]={};
    int dfs(string &s,int k,int i)
    {
        if(i==s.size())
        {
            return 1;
        } 
        if(s[i]=='0')
        {
            return 0;
        } 
        if(!dp[i]) 
        {
            for(long sz=1,num=0;i+sz<=s.size();sz++)
            {
                num=num*10+s[i+sz-1]-'0';
                if(num>k)
                {
                    break;
                } 
                dp[i]=(dp[i]+dfs(s,k,sz+i))%(1000000007);
            }
        }
        return dp[i];
    }
    int numberOfArrays(string s,int k) 
    {
        return dfs(s,k,0);
    }
};
