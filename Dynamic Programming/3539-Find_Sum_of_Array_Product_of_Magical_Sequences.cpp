class Solution {
public:
    int MOD = 1e9 + 7, m, n, k;
    int C[31][31]={{0}},dp[31][31][50][31];

    void Pascal()
    {
        if(C[0][0]==1)
        {
            return;
        }
        for(int i=1;i<=30;i++)
        {
            C[i][0]=C[i][i]=1;
            for(int j=1;j<=i/2;j++)
            {
                int Cij=(C[i-1][j-1]+C[i-1][j])%MOD;
                C[i][j]=C[i][i-j]=Cij;
            }
        }
    }
    int dfs(int m,int k,int i,unsigned flag,vector<int> &nums)
    {
        int bz=__builtin_popcount(flag);
        if(m<0 || k<0 || m+bz<k)
        {
            return 0;
        }
        if(m==0)
        {
            return (k==bz)?1:0;
        }
        if(i>=n)
        {
            return 0;
        }
        if(dp[m][k][i][flag]!=-1)
        {
            return dp[m][k][i][flag];
        }
        long long ans=0,powX=1;
        int x=nums[i];
        for(int f=0;f<=m;f++)
        {
            long long perm=1LL*C[m][f]*powX%MOD;
            unsigned newFlag=flag+f,nextFlag=newFlag>>1;
            bool bitSet=newFlag&1;
            ans=(ans+perm*dfs(m-f,k-bitSet,i+1,nextFlag,nums))%MOD;
            powX=powX*x%MOD;
        }
        return dp[m][k][i][flag]=ans;
    }
    int magicalSum(int m,int k,vector<int> &nums)
    {
        Pascal();
        this->m=m;
        this->k=k;
        n=nums.size();
        memset(dp,-1,sizeof(dp));
        return dfs(m,k,0,0,nums);
    }
};
