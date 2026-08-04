class Solution {
public:
    vector<int> findMissingElements(vector<int> &nums)
    {
        vector<int> ans;
        vector<bool> contains(101);
        int mn=INT_MAX,mx=INT_MIN;
        for(auto &i:nums)
        {
            mn=min(mn,i);
            mx=max(mx,i);
            contains[i]=true;
        }
        for(int i=mn;i<=mx;i++)
        {
            if(!contains[i])
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
