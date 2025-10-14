class Solution {
public:
    bool hasIncreasingSubarrays(vector<int> &nums,int k)
    {
        int knew=k-1,n=nums.size();
        if(knew==0)
        {
            return true;
        }
        for(int i=k+1;i<n;i++)
        {
            if(nums[i]>nums[i-1] && nums[i-k]>nums[i-k-1])
            {
                knew--;
            }
            else
            {
                knew=k-1;
            }
            if(knew==0)
            {
                return true;
            }
        }
        return false;
    }
};
