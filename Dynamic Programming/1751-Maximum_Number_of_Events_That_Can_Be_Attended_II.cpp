class Solution {
public:
    int attend(int i,int num,vector<vector<int>> &events,int n,vector<int> &next,vector<vector<int>> &dp)
    {
        if(i==n || num==0)
        {
            return 0;
        }
        if(dp[i][num]!=-1)
        {
            return dp[i][num];
        }
        int a=events[i][2]+attend(next[i],num-1,events,n,next,dp),s=attend(i+1,num,events,n,next,dp),ans=max(a,s);
        return dp[i][num]=ans;
    }
    int maxValue(vector<vector<int>> &events,int k)
    {
        int n=events.size();
        vector<int> next(n,n);
        vector<vector<int>> dp(n,vector<int>(k+1,-1));
        sort(events.begin(),events.end());
        for(int i=0;i<n;i++)
        {
            next[i]=upper_bound(events.begin()+i,events.end(),vector<int>{events[i][1]+1,0,0})-events.begin();
        }
        return attend(0,k,events,n,next,dp);
    }
};
