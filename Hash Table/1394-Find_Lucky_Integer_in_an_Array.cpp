class Solution {
public:
    int findLucky(vector<int> &arr)
    {
        unordered_map<int,int> m;
        vector<int> ans;
        for(auto &i:arr)
        {
            m[i]++;
        }
        for(auto &i:m)
        {
            if(i.second==i.first)
            {
                ans.push_back(i.first);
            }
        }
        return (ans.size()!=0?*max_element(ans.begin(),ans.end()):-1);
    }
};
