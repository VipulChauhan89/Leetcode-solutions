class Solution {
public:
    vector<int> findDuplicates(vector<int> &nums) 
    {
        vector<int> a;
        sort(nums.begin(),nums.end());    
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i-1]==nums[i])
            {
                a.push_back(nums[i-1]);
            }
        }
        return a;
    }
};
