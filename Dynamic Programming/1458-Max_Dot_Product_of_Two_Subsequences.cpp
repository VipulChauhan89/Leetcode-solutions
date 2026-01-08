class Solution {
public:
    int maxDotProduct(vector<int> &nums1,vector<int> &nums2)
    {
        int n1=nums1.size(),n2=nums2.size(),ans=INT_MIN;
        if(n1<n2)
        {
            return maxDotProduct(nums2,nums1);
        }
        int dp[2][501];
        fill(&dp[0][0],&dp[0][0]+2*501,INT_MIN);
        for(int i=n1-1;i>=0;i--)
        {
            for(int j=n2-1;j>=0;j--)
            {
                int x=nums1[i]*nums2[j],tmp=dp[i&1][j];
                tmp=max(tmp,x);
                tmp=max(tmp, x+(i+1<n1 && j+1<n2 ? dp[(i+1)&1][j+1]:0));
                tmp=max(tmp,(j+1<n2 ? dp[i&1][(j+1)] : INT_MIN));
                dp[i&1][j]=max(tmp,dp[(i+1)&1][j]);
                ans=max(ans,dp[i&1][j]);
            }
        }
        return ans;
    }
};
