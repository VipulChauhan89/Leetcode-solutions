class Solution {
public:
    int largestInteger(vector<int> &nums,int k)
    {
        int n=nums.size();
        unordered_map<int,int> mp;
        vector<int> ans;
        for(int i:nums)
        {
            mp[i]++;
        }
        if(k==1)
        {
            for(auto it:mp)
            {
                if(it.second==1)
                {
                    ans.push_back(it.first);
                }
            }
            if(ans.empty())
            {
                return -1;
            }
            return *max_element(ans.begin(),ans.end());
        }
        if(k==n)
        {
            return *max_element(nums.begin(),nums.end());
        }
        if(1<k && k<n)
        {
            if(mp[nums[0]]==1)
            {
                ans.push_back(nums[0]);
            }
            if(mp[nums[n-1]]==1)
            {
                ans.push_back(nums[n-1]);
            }
            if(ans.empty())
            {
                return -1;
            }
            return *max_element(ans.begin(),ans.end());
        }
        return -1;
    }
};
