class Solution {
public:
    bool kLengthApart(vector<int> &nums,int k)
    {
        int n=nums.size(),pre_index;
        bool flag=true;
        for(int i=0;i<n;i++)
        {
            if(flag && nums[i]==1)
            {
                flag=false;
                pre_index=i;
                continue;
            }
            if(nums[i]==1)
            {
                if(i-pre_index-1>=k)
                {
                    pre_index=i;
                }
                else
                {
                    return false;
                }
            }
        }
        return true;
    }
};
