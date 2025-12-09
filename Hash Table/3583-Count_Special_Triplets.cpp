class Solution {
public:
    int specialTriplets(vector<int> &nums)
    {
        int M=100001,n=nums.size(),mod=1e9+7;
        vector<int> freq(M,0),prev(M,0);
        long long count=0;
        for(int x:nums)
        {
            freq[x]++;
        }
        prev[nums[0]]++;
        for(int i=1;i<n-1;i++)
        {
            int x=nums[i],x2=x<<1;
            if(x2<M)
            {
                count+=(long long)prev[x2]*(freq[x2]-prev[x2]-(x==0));
            }
            prev[x]++;
        }
        return count%mod;
    }
};
