class Solution {
public:
    int solve(vector<int> &nums,vector<bool> &isVisited,unordered_map<vector<bool>,int> &dp,int operation)
    {
        int n=nums.size(),res=0;
        if(dp.count(isVisited))
        {
            return dp[isVisited];
        } 
        for(int i=0;i<n;i++)
        {
            if(isVisited[i])
            {
                continue;
            } 
            for(int j=i+1;j<n;j++)
            {
                if(isVisited[j])
                {
                    continue;
                } 
                isVisited[i]=isVisited[j]=1;
                res=max(res,operation*__gcd(nums[i],nums[j])+solve(nums,isVisited,dp,operation+1));
                isVisited[i]=isVisited[j]=0;
            }
        }
        return dp[isVisited]=res;
    }
    int maxScore(vector<int>& nums) 
    {
        unordered_map<vector<bool>,int> dp;
        int n=nums.size();
        vector<bool> isVisited(n,0);
        return solve(nums,isVisited,dp,1);
    }
};
