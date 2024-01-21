class Solution {
public:
    int minimumCost(vector<int> &nums) 
    { 
        int n=nums.size(),a=nums[0],b=INT_MAX,b_index=0,c=INT_MAX;
        for(int i=1;i<n;i++)
        {
            if(nums[i]<b)
            {
                c=b;
                b=nums[i];
                b_index=i;
            }
            else if(nums[i]<c)
            {
                c=nums[i];
            }
        }
        return a+b+c;
    }
};
