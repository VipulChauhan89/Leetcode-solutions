class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        vector<int> v;
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++)
        {
            if(m.find(nums[i])!=m.end())
            {
                v.push_back(m[nums[i]]);
                v.push_back(i);
                break;
            }
            else
            {
                m[target-nums[i]]=i;                  
            }
        }
        return v;
    }
};
