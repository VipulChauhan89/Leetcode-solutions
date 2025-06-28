class Solution {
public:
    vector<int> maxSubsequence(vector<int> &nums,int k)
    {
        int n=nums.size();
        vector<pair<int, int>> v;
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            v.push_back({nums[i],i});
        }
        sort(v.begin(),v.end(),[](auto &a,auto &b)
        {
            return a.first>b.first;
        });
        v.resize(k);
        sort(v.begin(),v.end(),[](auto &a,auto &b)
        {
            return a.second<b.second;
        });
        for(auto &i:v)
        {
            ans.push_back(i.first);
        }
        return ans;
    }
};