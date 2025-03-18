class Solution {
public:
    int longestNiceSubarray(vector<int> &nums) 
    {
        int n=nums.size(),mxlen=1,l=0,bits=0;
        for(int i=0;i<n;i++)
        {
            while((bits&nums[i])!=0)
            {
                bits^=nums[l];
                l++;
            }
            bits|=nums[i];
            mxlen=max(mxlen,i-l+1);
        }
        return mxlen;
    }
};
