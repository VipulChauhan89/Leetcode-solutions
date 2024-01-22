class Solution {
public:
    vector<int> findErrorNums(vector<int> &nums) 
    {
        vector<int> ans;
        sort(nums.begin(),nums.end());
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i-1]==nums[i])
            {
                ans.push_back(nums[i-1]);
                nums.erase(nums.begin()+i);
                break;
            }
        }
        for(int i=0;i<=nums.size();i++)
        {
            if(nums[i]!=i+1)
            {
                ans.push_back(i+1);
                break;
            }
        }
        return ans;
    }
};
