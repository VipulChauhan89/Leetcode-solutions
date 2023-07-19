class Solution {
public:
    int minimumIndex(vector<int> &nums) 
    {
        int n=nums.size();
        unordered_map<int,int> m;
        int mx=0,de=0,dc=0,l=0;
        for(auto i:nums)
        {
            m[i]++;
            if(m[i]>mx)
            {
                mx=m[i];
                de=i;
                dc=mx;
            }
        }
        if(dc*2<=n)
        {
            return -1;
        }
        for(int i=0;i<n;i++)
        {
            if(nums[i]==de)
            {
                l++;
            }
            int r=dc-l;
            if(l*2>i+1 && r*2>n-i-1)
            {
                return i;
            }
        }
        return -1;
    }
};
