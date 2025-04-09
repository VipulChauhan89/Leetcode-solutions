class Solution {
public:
    int minOperations(vector<int> &nums,int k) 
    {
        sort(nums.begin(),nums.end());
        int mn=nums[0],count=0;
        if(mn<k)
        {
            return -1;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>k)
            {
                count++;
            }
            while(i+1<nums.size() && nums[i]==nums[i+1])
            {
                i++;
            }
        }
        return count;
    }
};
