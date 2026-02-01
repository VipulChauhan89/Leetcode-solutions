class Solution {
public:
    int minimumCost(vector<int> &nums)
    {
        int n=nums.size(),sum=nums[0],a=INT_MAX,b=INT_MAX;
        for(int i=1;i<n;i++)
        {
            if(nums[i]<a)
            {
                b=a;
                a=nums[i];
            }
            else if(nums[i]>=a && nums[i]<b)
            {
                b=nums[i];
            }
        }
        sum+=(a+b);
        return sum;
    }
};
