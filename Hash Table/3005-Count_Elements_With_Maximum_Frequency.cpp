class Solution {
public:
    int maxFrequencyElements(vector<int> &nums) 
    {
        int mx=INT_MIN,ans=0;
        unordered_map<int,int> m;
        for(auto i:nums)
        {
            m[i]++;
            mx=max(mx,m[i]);
        }
        for(auto &i:m)
        {
            if(i.second==mx)
            {
                ans+=i.second;
            }
        }
        return ans;
    }
};
