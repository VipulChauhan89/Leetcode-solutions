class Solution {
public:
    int minKBitFlips(vector<int> &nums,int k) 
    {
        int n=nums.size(),flip=0,ans=0;
        vector<int> flipped(n,0);
        for(int i=0;i<n;i++)
        {
            if(i>=k)
            {
                flip^=flipped[i-k];
            }
            if(flip==nums[i])
            {
                if(i+k>n)
                {
                    return -1;
                }
                flipped[i]=1;
                flip^=1;
                ans++;
            }
        }
        return ans;
    }
};
