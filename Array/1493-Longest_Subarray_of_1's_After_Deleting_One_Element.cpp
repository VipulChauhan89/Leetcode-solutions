class Solution {
public:
    int longestSubarray(vector<int> &nums)
    {
        int ans=0;
        int n=nums.size(),count=0,l=0,r=0;
        while(r<n)
        {
            if(nums[r]==0)
            {
                count++;
            }
            while(count>1)
            {
                if(nums[l]==0)
                {
                    count--;
                }
                l++;
            }
            ans=max(ans,r-l);
            r++;
        }
        return ans;
    }
};
