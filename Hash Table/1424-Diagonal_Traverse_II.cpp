class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>> &nums) 
    {
        int mx=0;
        vector<int> ans;
        unordered_map<int,vector<int>> m;
        for(int i=0;i<nums.size();i++)
        {
            mx=(mx<nums[i].size())?nums.size():mx;
            for(int j=0;j<nums[i].size();j++)
            {
                m[i+j].insert(m[i+j].begin(),nums[i][j]);
            }
        }    
        for(int i=0;i<4*mx;i++)
        {
            for(auto j:m[i])
            {
                ans.push_back(j);
            }
        }
        return (nums.size()==1)?nums[0]:ans;
    }
};
