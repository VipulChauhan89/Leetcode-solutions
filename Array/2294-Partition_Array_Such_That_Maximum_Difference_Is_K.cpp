class Solution {
public:
    int partitionArray(vector<int> &nums,int k) 
    {
        sort(nums.begin(),nums.end());
        int n=nums.size(),ans=1,mn=nums[0];
        for(int i=1;i<n;i++)
        {
            if(nums[i]-mn>k)
            {
                ans++;
                mn=nums[i];
            }
        }
        return ans;
    }
};
