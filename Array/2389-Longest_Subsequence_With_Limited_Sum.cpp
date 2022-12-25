class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) 
    {
        vector<int> ans;
        sort(nums.begin(),nums.end());
        for(int i=1;i<nums.size();i++)
        {
            nums[i]+=nums[i-1];
        }
        for(auto i:queries)
        {
            int j;
            for(j=0;j<nums.size();j++)
            {
                if(nums[j]>i)
                {
                    break;
                }
            }
            ans.push_back(j);
        }
        return ans;
    }
};
