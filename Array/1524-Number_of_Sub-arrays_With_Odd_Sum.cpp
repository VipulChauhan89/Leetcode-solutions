class Solution {
public:
    int numOfSubarrays(vector<int> &arr) 
    {
        int n=arr.size(),mod=1e9+7;
        long long count=0,prefixSum=0;
        for(int i=0;i<n;i++)
        {
            prefixSum+=arr[i];
            count+=prefixSum%2;
        }
        count+=(arr.size()-count)*count;
        return count%mod;
    }
};
