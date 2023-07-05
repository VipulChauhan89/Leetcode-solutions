class Solution {
public:
    int longestSubarray(vector<int> &nums) 
    {
        int n=nums.size();
        int left=0,zero=0,ans=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0)
            {
                zero++;
            }
            while(zero>1)
            {
                if(nums[left]==0)
                {
                    zero--;
                }
                left++;
            }
            ans=max(ans,i-left+1-zero);
        }
        return (ans==n)?ans-1:ans;
    }
};
