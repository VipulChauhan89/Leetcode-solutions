class Solution {
public:
    vector<vector<int>> findMatrix(vector<int> &nums) 
    {
        int mx=INT_MIN;
        unordered_map<int,int> m;
        for(auto i:nums)    
        {
            m[i]++;
            mx=max(mx,m[i]);
        }
        vector<vector<int>> ans(mx);
        for(auto &i:m)
        {
            while(i.second!=0)
            {
                i.second--;
                ans[i.second].push_back(i.first);
            }
        }
        return ans;
    }
};
