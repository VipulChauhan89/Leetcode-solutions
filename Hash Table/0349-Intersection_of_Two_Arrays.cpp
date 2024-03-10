class Solution {
public:
    vector<int> intersection(vector<int> &nums1,vector<int> &nums2) 
    {
        vector<int> ans;
        unordered_set<int> s;
        for(auto i:nums1)
        {
            s.insert(i);
        }
        for(auto i:nums2)
        {
            if(s.find(i)!=s.end())
            {
                ans.push_back(i);
                s.erase(s.find(i));
            }
        }
        return ans;
    }
};
