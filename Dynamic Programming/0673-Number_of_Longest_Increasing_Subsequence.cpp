class Solution {
public:
    int findNumberOfLIS(vector<int> &nums) 
    {
        int n=nums.size(),mx=1,ans=0;
        vector<int> result(n,1),count(n,1);
        for(int i=0;i<n;i++)
        {
            for(int j=i-1;j>=0;j--)
            {
                if(nums[i]<nums[j])
                {
                    continue;
                }
                else if(nums[i]>nums[j])
                {
                    if(result[j]+1>result[i])
                    {
                        result[i]=result[j]+1;
                        count[i]=count[j];
                    }
                    else if(result[j]+1==result[i])
                    {
                        count[i]+=count[j];
                    }
                }
            }
            mx=max(mx,result[i]);
        }
        for(int i=0;i<n;i++)
        {
            if(result[i]==mx)
            {
                ans+=count[i];
            }
        }
        return ans;
    }
};
