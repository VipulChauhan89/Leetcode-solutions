class Solution {
public:
    void generatePattern(int m,vector<vector<int>> &patterns,vector<int> &current)
    {
        if(current.size()==m)
        {
            patterns.push_back(current);
            return;
        }
        for(int i=0;i<3;i++)
        {
            if(current.empty() || current.back()!=i)
            {
                current.push_back(i);
                generatePattern(m,patterns,current);
                current.pop_back();
            }
        }
    }
    int colorTheGrid(int m,int n) 
    {
        int mod=1e9+7,ans=0;
        vector<vector<int>> patterns;
        vector<int> current;
        generatePattern(m,patterns,current);
        int pCount=patterns.size();
        vector<int> dp(pCount,1);
        vector<vector<int>> compatible(pCount);
        for(int i=0;i<pCount;i++)
        {
            for(int j=0;j<pCount;j++)
            {
                bool flag=true;
                for(int k=0;k<m;k++)
                {
                    if(patterns[i][k]==patterns[j][k])
                    {
                        flag=false;
                        break;
                    }
                }
                if(flag)
                {
                    compatible[i].push_back(j);
                }
            }
        }
        for(int i=1;i<n;i++)
        {
            vector<int> newDp(pCount,0);
            for(int j=0;j<pCount;j++)
            {
                for(auto &k:compatible[j])
                {
                    newDp[k]=(newDp[k]+dp[j])%mod;
                }
            }
            dp=newDp;
        }
        for(auto &i:dp)
        {
            ans=(ans+i)%mod;
        }
        return ans;
    }
};
