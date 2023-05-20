class Solution {
public:
    int matrixSum(vector<vector<int>> &nums) 
    {
        int n=nums.size(),m=nums[0].size(),score=0;
        for(auto &row:nums)
        {
            sort(row.begin(),row.end(),greater<int>());
        }
        for(int j=0;j<m;j++) 
        {
            int mx=0;
            for(int i=0;i<n;i++) 
            {
                if(!nums[i].empty() && nums[i][j]>mx) 
                {
                    mx=nums[i][j];
                }
            }
            score+=mx;
            for(int i=0;i<n;i++) 
            {
                if(!nums[i].empty() && nums[i][j]==mx) 
                {
                    nums[i].pop_back();
                }
            }
        }
        return score;
    }
};
