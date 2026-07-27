class Solution {
public:
    int maxProduct(vector<int> &nums)
    {
        int n=nums.size();
        sort(nums.begin(),nums.end());  
        return max((nums[n-1]-1)*(nums[n-2]-1),(nums[0]-1)*(nums[1]-1));
    }
};
