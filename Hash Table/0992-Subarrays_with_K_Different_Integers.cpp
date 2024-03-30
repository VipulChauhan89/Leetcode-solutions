class Solution {
public:
    int subarrayWithAtmostK(vector<int> &nums,int k)
    {
        unordered_map<int,int> m;
        int l=0,r=0,ans=0;
        while(r<nums.size())
        {
            m[nums[r]]++;
            while(m.size()>k)
            {
                m[nums[l]]--;
                if(m[nums[l]]==0)
                {
                    m.erase(nums[l]);
                }
                l++;
            }
            ans+=r-l+1;
            r++;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int> &nums,int k) 
    {
        return subarrayWithAtmostK(nums,k)-subarrayWithAtmostK(nums,k-1);
    }
};
