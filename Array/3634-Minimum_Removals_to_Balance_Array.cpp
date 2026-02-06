class Solution {
public:
    int minRemoval(vector<int> &nums,int k)
    {
        sort(nums.begin(),nums.end());
        int n=nums.size(),i=0,maxLen=0;
        for(int j=0;j<n;j++)
        {
            while((long long)nums[j]>(long long)nums[i]*k)
            {
                i++;
            }
            maxLen=max(maxLen,j-i+1);
        }
        return n-maxLen;
    }
};
