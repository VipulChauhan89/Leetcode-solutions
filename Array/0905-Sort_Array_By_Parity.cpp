class Solution {
public:
    vector<int> sortArrayByParity(vector<int> &nums) 
    {
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]%2==0)
            {
                nums.insert(nums.begin(),nums[i]);
                nums.erase(nums.begin()+i+1);
            }
        }
        return nums;
    }
};
