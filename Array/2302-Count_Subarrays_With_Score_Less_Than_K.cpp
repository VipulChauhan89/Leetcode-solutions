class Solution {
public:
    long long countSubarrays(vector<int> &nums,long long k) 
    {
        int n=nums.size();
        long long count=0,sum=0,l=0;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            while(sum*(i-l+1)>=k)
            {
                sum-=nums[l++];
            }
            count+=(i-l+1);
        }
        return count;
    }
};
