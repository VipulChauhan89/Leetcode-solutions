class Solution {
public:
    void sortColors(vector<int> &nums) 
    {
        int zero=0,one=0;
        for(auto i:nums)
        {
            if(i==0)
            {
                zero++;
            }
            else if(i==1)
            {
                one++;
            }
        }
        int i=0;
        for(;i<zero;i++)
        {
            nums[i]=0;
        }
        for(;i<zero+one;i++)
        {
            nums[i]=1;
        }
        for(;i<nums.size();i++)
        {
            nums[i]=2;
        }
    }
};
