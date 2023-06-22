class Solution {
public:

    
    int getAns(vector<int> &Arr,int ind,int buy,int n,int fee,vector<vector<int>> &dp)
    {
        if(ind==n)
        {
            return 0;
        } 
        if(dp[ind][buy]!=-1)
        {
            return dp[ind][buy];
        } 
        int profit;
        if(buy==0)
        {
            profit=max(0+getAns(Arr,ind+1,0,n,fee,dp),-Arr[ind]+getAns(Arr,ind+1,1,n,fee,dp));
        }
        if(buy==1)
        {
            profit=max(0+getAns(Arr,ind+1,1,n,fee,dp),Arr[ind]-fee+getAns(Arr,ind+1,0,n,fee,dp));
        }
        return dp[ind][buy]=profit;
    }
    int maxProfit(vector<int> &Arr,int fee) 
    {
        vector<vector<int>> dp(Arr.size(),vector<int>(2,-1));
        if(Arr.size()==0)
        {
            return 0;
        } 
        int ans=getAns(Arr,0,0,Arr.size(),fee,dp);
        return ans;
    }
};
