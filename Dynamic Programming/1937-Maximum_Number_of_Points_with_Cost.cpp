class Solution {
public:
    long long maxPoints(vector<vector<int>> &points) 
    {
        int r=points.size(),c=points[0].size();
        vector<long long> dp(c,0);
        for(int i=0;i<c;i++)
        {
            dp[i]=points[0][i];
        }
        for(int i=1;i<r;i++) 
        {
            vector<long long> leftMax(c,0),rightMax(c,0),newDp(c,0);
            leftMax[0]=dp[0];
            for(int j=1;j<c;j++) 
            {
                leftMax[j]=max(leftMax[j-1],dp[j]+j);
            }
            rightMax[c-1]=dp[c-1]-(c-1);
            for(int j=c-2;j>=0;j--) 
            {
                rightMax[j]=max(rightMax[j+1],dp[j]-j);
            }
            for(int j=0;j<c;j++) 
            {
                newDp[j]=max(leftMax[j]-j,rightMax[j]+j)+points[i][j];
            }
            dp=newDp;
        }
        return *max_element(dp.begin(),dp.end());
    }
};
