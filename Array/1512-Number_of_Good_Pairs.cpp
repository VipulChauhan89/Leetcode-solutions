class Solution {
public:
    int numIdenticalPairs(vector<int> &nums) 
    {
        int ans=0;
        unordered_map<int,int> m;
        for(auto &i:nums)
        {
            ans+=m[i]++;
        }
        return ans;
    }
};
