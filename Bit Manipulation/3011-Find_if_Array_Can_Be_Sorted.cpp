class Solution {
public:
    int countSetBits(int num)
    {
        int count=0;
        while(num>0) 
        {
            count+=num&1;
            num>>=1;
        }
        return count;
    }
    bool check(vector<int> &nums)
    {
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i-1]>nums[i])
            {
                return false;
            }
        }
        return true;
    }
    bool canSortArray(vector<int> &nums) 
    {
        vector<int> c(101);
        int n=nums.size(),i=0,j=0;
        for(auto k:nums)
        {
            c[i++]=countSetBits(k);
        }
        while(j<n)
        {
            for(int k=1;k<n;k++)
            {
                if(c[k]==c[k-1] && nums[k]<nums[k-1])
                {
                    swap(nums[k],nums[k-1]);
                }
            }
            if(check(nums))
            {
                return true;
            }
            j++;
        }
        return false;
    }
};
