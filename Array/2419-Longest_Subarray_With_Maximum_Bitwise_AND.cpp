class Solution {
public:
    int longestSubarray(vector<int> &nums)
    {
        int mx=*max_element(nums.begin(),nums.end()),streak=0,mxStreak=0;
        for(auto &i:nums)
        {
            if(i==mx)
            {
                streak++;
                if(streak>mxStreak)
                {
                    mxStreak=streak;
                }
            }
            else
            {
                streak=0;
            }
        }
        return mxStreak;
    }
};
