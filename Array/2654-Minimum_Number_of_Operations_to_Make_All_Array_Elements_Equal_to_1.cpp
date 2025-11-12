class Solution {
public:
    int minOperations(vector<int> &nums)
    {
        int n=nums.size(),gcd=nums[0];
        for(int i=0;i<n;i++)
        {
            if(nums[i]==1)
            {
                int ans=0;
                for(int x:nums)
                {
                    if(x!=1)
                    {
                        ans++;
                    }
                }
                return ans;
            }
            if(i<n-1)
            {
                gcd=__gcd(gcd,nums[i+1]);
            }
        }
        if(gcd!=1)
        {
            return -1;
        }
        int ans=1e9;
        for(int i=0;i<n;i++)
        {
            int g=nums[i];
            for(int j=i+1;j<n;j++)
            {
                g=__gcd(g,nums[j]);
                if(g==1)
                {
                    ans=min(ans,j-i-1+(int)nums.size());
                    break;
                }
            }
        }
        return ans;
    }
};
