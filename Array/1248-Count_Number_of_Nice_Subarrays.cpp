class Solution {
public:
    int numberOfSubarrays(vector<int> &nums,int k) 
    {
        int n=nums.size();
        vector<int> a(n+1,0);
        a[0]=1;
        int ans=0,t=0;
        for(auto i:nums)
        {
            t+=i&1;
            if(t-k>=0)
            {
                ans+=a[t-k];
            }
            a[t]++;
        }
        return ans;
    }
};
