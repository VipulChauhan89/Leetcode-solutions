class Solution {
public:
    int mod=1000000007;
    int numSubseq(vector<int> &nums,int target) 
    {
        sort(nums.begin(),nums.end());
        int ans=0,n=nums.size(),left=0,right=n-1;
        vector<int> pow2(n+1,1);
        for(int i=1;i<=n;i++) 
        {
            pow2[i]=(2*pow2[i-1])%mod;
        }
        while(left<=right) 
        {
            if(nums[left]+nums[right]<=target) 
            {
                ans=(ans+pow2[right-left])%mod;
                left++;
            } 
            else 
            {
                right--;
            }
        }
        return ans;
    }
};
