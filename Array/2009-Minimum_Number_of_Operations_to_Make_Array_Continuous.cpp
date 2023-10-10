class Solution {
public:
    int minOperations(vector<int> &nums) 
    {
        sort(nums.begin(),nums.end());
        int n=nums.size(),left=0,maxCount=1,currentCount=1;
        for(int right=1;right<n;right++) 
        {
            if(nums[right]==nums[right-1]) 
            {
                continue;
            }
            while(nums[right]-nums[left]>n-1) 
            {
                if(left<n && nums[left+1]==nums[left])
                {
                    currentCount++;
                }
                left++;
                currentCount--;
            }
            currentCount++;
            maxCount=max(maxCount,currentCount);
        }
        return n-maxCount;
    }
};
