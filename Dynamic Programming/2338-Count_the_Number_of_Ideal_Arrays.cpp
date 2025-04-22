class Solution {
public:
    int idealArrays(int n,int maxValue) 
    {
        int mod=1e9+7;
        long long ans=0;
        vector<vector<int>> dp(10005,vector<int>(20)),count(10005,vector<int>(20));
        for(int i=1;i<=maxValue;i++) 
        {
		    dp[i][1]=(dp[i][1]+1)%mod;
		    for(int j=i+i;j<=maxValue;j+=i) 
            {
			    for(int k=1;k<=18;k++) 
                {
				    dp[j][k]=(dp[j][k]+dp[i][k-1])%mod;
			    }
		    }
	    }
	    for(int i=0;i<=n;i++) 
        {
		    count[i][0]=1;
		    for(int j=1;j<=min(i,18);j++) 
            {
			    count[i][j]=(count[i-1][j]+count[i-1][j-1])%mod;
		    }
	    }
	    for(int i=1;i<=maxValue;i++) 
        {
		    for(int j=1;j<=18;j++) 
            {
			    ans=(ans+1ll*dp[i][j]*count[n-1][j-1]%mod)%mod;
		    }
	    }
	    return ans;
    }
};
