class Solution {
public:
    vector<bool> pathExistenceQueries(int n,vector<int> &nums,int maxDiff,vector<vector<int>> &queries)
    {
        vector<int> component(n,0);
        int compNo=0;
        for(int i=1;i<n;i++)
        {
            if(nums[i]-nums[i-1]>maxDiff)
            {
                compNo++;
            }
            component[i]=compNo;
        }
        vector<bool> ans;
        for(auto &it:queries)
        {
            ans.push_back(component[it[0]]==component[it[1]]);
        }
        return ans;
    }
};
