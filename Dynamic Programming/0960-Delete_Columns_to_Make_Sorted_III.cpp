class Solution {
public:
    bool isSorted(const vector<string> &strs,int j,int i)
    {
        for(const string &s:strs)
        {
            if(s[j]>s[i])
            {
                return false;
            }
        }
        return true;
    }
    int minDeletionSize(vector<string> &strs)
    {
        int m=strs[0].size();
        vector<int> dp(m,1);
        for(int i=1;i<m;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(isSorted(strs,j,i))
                {
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
        }
        int longest=*max_element(dp.begin(),dp.end());
        return m-longest;
    }
};
