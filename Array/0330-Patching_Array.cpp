class Solution {
public:
    int minPatches(vector<int> &nums,int n) 
    {
        long long m=1,ans=0;
        size_t i=0;
        while(m<=n)
        {
            if(i<nums.size() && nums[i]<=m)
            {
                m+=nums[i];
                i++;
            }
            else
            {
                m+=m;
                ans++;
            }
        }
        return ans;
    }
};
