class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int> &nums) 
    {
        int n=nums.size();
        vector<int> result(n),prefixSum(n),suffixSum(n);
        prefixSum[0]=nums[0];
        suffixSum[n-1]=nums[n-1];
        for(int i=1;i<n;i++) 
        {
            prefixSum[i]=prefixSum[i-1]+nums[i];
            suffixSum[n-i-1]=suffixSum[n-i]+nums[n-i-1];
        }
        for(int i=0;i<n;i++) 
        {
            result[i]=((nums[i]*i)-prefixSum[i])+(suffixSum[i]-(nums[i]*(n-i-1)));
        }
        return result;
    }
};
