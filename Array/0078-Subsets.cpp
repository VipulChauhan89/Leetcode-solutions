class Solution {
public:
    vector<vector<int>> subsets(vector<int> &nums) 
    {
        vector<vector<int>> ans={{}};
        for(auto i:nums)
        {
            int n=ans.size();
            for(int j=0;j<n;j++)
            {
                vector<int> a=ans[j];
                a.push_back(i);
                ans.push_back(a);
            }
        }
        return ans;
    }
};
