class Solution {
public:
    int maxDistinctElements(vector<int> &nums,int k)
    {
        sort(nums.begin(),nums.end());
        int n=nums.size(),ans=0,prev=INT_MIN;
        for(int i=0;i<n;i++)
        {
            int l=max(nums[i]-k,prev+1);
            if(l<=nums[i]+k)
            {
                prev=l;
                ans++;
            }
        }
        return ans;
    }
};
