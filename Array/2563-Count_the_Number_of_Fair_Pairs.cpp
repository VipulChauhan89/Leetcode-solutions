class Solution {
public:
    long long countFairPairs(vector<int> &nums,int lower,int upper) 
    {
        long long ans=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i+1<nums.size();i++)
        {
            int mn=lower-nums[i],mx=upper-nums[i];
            auto h=upper_bound(nums.begin()+i+1,nums.end(),mx),l=lower_bound(nums.begin()+i+1,nums.end(),mn);
            ans+=(h-l);
        }
        return ans;
    }
};
