class Solution {
public:
    vector<int> getMaximumXor(vector<int> &nums,int maximumBit) 
    {
        int n=nums.size(),x=nums[0],mx=pow(2,maximumBit)-1;
        vector<int> ans(n);
        for(int i=1;i<n;i++)
        {
            x^=nums[i];
        }
        for(int i=0;i<n;i++)
        {
            ans[i]=x^mx;
            x^=nums[n-1-i];
        }
        return ans;
    }
};
