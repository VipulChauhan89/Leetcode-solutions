class Solution {
public:
    long long maximumTripletValue(vector<int> &nums) 
    {
        int n=nums.size();
        long long mx=0;
        for(int i=0;i<n;i++) 
        {
            for(int j=n-1;j>i;j--) 
            {
                for(int k=i+1;k<j;k++) 
                {
                    mx=max(mx,1LL*(nums[i]-nums[k])*nums[j]);
                }
            }
        }
        return (mx<0?0:mx);
    }
};
