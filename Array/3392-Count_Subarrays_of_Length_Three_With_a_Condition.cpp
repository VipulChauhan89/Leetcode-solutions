class Solution {
public:
    int countSubarrays(vector<int> &nums) 
    {
        int count=0,n=nums.size();
        for(int i=2;i<n;i++)
        {
            if((nums[i-2]+nums[i])*2==nums[i-1])
            {
                count++;
            }
        }
        return count;
    }
};
