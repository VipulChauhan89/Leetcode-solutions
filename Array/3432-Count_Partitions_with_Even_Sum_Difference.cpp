class Solution {
public:
    int countPartitions(vector<int> &nums)
    {
        int n=nums.size(),ts=0,cs=0,count=0;
        for(int i:nums)
        {
            ts+=i;
        }
        for(int i=0;i<n-1;i++)
        {
            cs+=nums[i];
            ts-=nums[i];
            if((ts-cs)%2==0)
            {
                count++;
            }
        }
        return count;
    }
};
