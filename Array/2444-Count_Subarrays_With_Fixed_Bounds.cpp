class Solution {
public:
    long long countSubarrays(vector<int> &nums,int minK,int maxK) 
    {
        long long ans=0;
        int badi=-1,mn=-1,mx=-1,n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]<minK || nums[i]>maxK)
            {
                badi=i;
            }
            if(nums[i]==minK)
            {
                mn=i;
            }
            if(nums[i]==maxK)
            {
                mx=i;
            }
            ans+=max(0,min(mn,mx)-badi);
        }
        return ans;
    }
};
