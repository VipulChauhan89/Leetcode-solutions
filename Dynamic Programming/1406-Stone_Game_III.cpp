class Solution {
public:
    int n;
    vector<int>dp;
    int STONE(vector<int> &stoneValue,int cur)
    {
        int sum=0;
        if(cur==n) 
        {
            return 0;
        }
        if(dp[cur]>INT_MIN) 
        {
            return dp[cur];
        }
        for(int i=cur;(i<cur+3) && (i<n);i++)
        {
            sum+=stoneValue[i];
            dp[cur]=max(dp[cur],sum-STONE(stoneValue,i+1));
        }
        return dp[cur];
    }
    string stoneGameIII(vector<int> &stoneValue) 
    {
        n=(int)stoneValue.size();
        dp.resize(n,INT_MIN);
        int score=STONE(stoneValue,0);
        if(score>0) 
        {
            return "Alice";
        }
        else if(score<0) 
        {
            return "Bob";
        }
        else 
        {
            return "Tie";
        }
    }
};
