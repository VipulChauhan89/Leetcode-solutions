class Solution {
public:
    int largestVariance(string s) 
    {
        int result=0;
        for(int i=0;i<26;i++)
        {
            for(int j=0;j<26;j++)
            {
                if(i==j)
                {
                    continue;
                }
                int dp=0,dp1=INT_MIN;
                for(int k=0;k<s.size();k++)
                {
                    char c=s[k];
                    if(c-'a'==i)
                    {
                        dp=max(1,dp+1);
                        if(dp1!=INT_MIN)
                        {
                            dp1=dp1+1;
                        }
                    }
                    else if(c-'a'==j)
                    {
                        if(dp1==INT_MIN)
                        {
                            dp1=max(-1,dp-1);
                        }
                        else
                        {
                            dp1=max(max(-1,dp-1),dp1-1);
                        }
                        dp=dp-1;
                    }   
                    result=max(result,dp1);
                }
            }
        }
        return result;
    }
};
