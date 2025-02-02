class Solution {
public:
    bool check(vector<int> &nums) 
    {
        int n=nums.size(),count=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]>nums[(i+1)%n])
            {
                count++;
            }
            if(count>1)
            {
                break;
            }
        }
        return count<=1;
    }
};
