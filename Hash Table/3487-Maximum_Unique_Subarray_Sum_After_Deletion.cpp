class Solution {
public:
    int maxSum(vector<int> &nums)
    {
        int ans=0;
        set<int> s;
        for(auto &i:nums)
        {
            s.insert(i);
        }
        for(auto &i:s)
        {
            if(i>0)
            {
                ans+=i;
            }
        }
        return (ans==0?*s.rbegin():ans);
    }
};
