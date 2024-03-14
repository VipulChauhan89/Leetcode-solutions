class Solution {
public:
    int most(vector<int> &nums,int goal)
    {
        int t=0,sum=0,ans=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            while(sum>goal && t<=i)
            {
                sum-=nums[t];
                t++;
            }
            ans+=i-t+1;
        }
        return ans;
    }
    int numSubarraysWithSum(vector<int> &nums,int goal) 
    {
        return most(nums,goal)-most(nums,goal-1);
    }
};
