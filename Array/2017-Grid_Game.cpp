class Solution {
public:
    long long gridGame(vector<vector<int>> &grid) 
    {
        int n=grid[0].size();
        long long t=0,b=0,ans=LLONG_MAX;
        for(int i=0;i<n;i++)
        {
            t+=grid[0][i];
        }    
        for(int i=0;i<n;i++)
        {
            t-=grid[0][i];
            ans=min(ans,max(t,b));
            b+=grid[1][i];
        }
        return ans;
    }
};
