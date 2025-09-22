class Solution {
public:
    int maxFrequencyElements(vector<int> &nums)
    {
        int mx=0,ans=0;
        unordered_map<int,int> m;
        for(auto &i:nums)
        {
            m[i]++;
            mx=max(mx,m[i]);
        }
        for(auto &i:nums)
        {
            if(m[i]==mx)
            {
                ans++;
            }
        }
        return ans;
    }
};
