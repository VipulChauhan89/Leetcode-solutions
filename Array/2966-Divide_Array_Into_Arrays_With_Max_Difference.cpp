class Solution {
public:
    vector<vector<int>> divideArray(vector<int> &nums,int k) 
    {
        int n=nums.size(),index=0;
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans(n/3,vector<int>(3));
        for(int i=0;i<n;i+=3)
        {
            if(i+2<n && nums[i+2]-nums[i]<=k)
            {
                ans[index]= {nums[i],nums[i+1],nums[i+2]};
                index++;
            }
            else
            {
                return {};
            }
        }
        return ans;
    }
};
