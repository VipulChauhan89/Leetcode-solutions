class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) 
    {
        unordered_map<int,int> m;
        int max_count=0;
        for(auto i:nums)
        {
            m[i]++;
            max_count=max(max_count, m[i]);
        }
        vector<vector<int>> v(max_count);
        for(auto i:m)
        {
            int j=0;
            while(i.second--)
            {
                v[j].push_back(i.first);
                j++;
            }
        }
        return v;
    }
};
