class Solution {
public:
    vector<int> getSneakyNumbers(vector<int> &nums)
    {
        vector<int> ans;
        unordered_map<int,int> m;
        for(auto &i:nums)
        {
            m[i]++;
            if(m[i]==2)
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
