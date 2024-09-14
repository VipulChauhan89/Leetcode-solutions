class Solution {
public:
    int longestSubarray(vector<int> &nums) 
    {
        int ans=1,mx=*max_element(nums.begin(),nums.end()),temp_ans=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==mx)
            {
                temp_ans++;
            }
            else
            {
                ans=max(ans,temp_ans);
                temp_ans=0;
            }
        }
        return max(ans,temp_ans);
    }
};
