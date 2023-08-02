class Solution {
public:
    vector<vector<int>> ans;
    void solve(vector<int> &arr,vector<int> &v)
    {
        if(arr.empty())
        {
            ans.push_back(v);
            return ;
        }
        for(int i=0;i<arr.size();i++)
        {
            v.push_back(arr[i]);
            arr.erase(arr.begin()+i);
            solve(arr,v);
            arr.insert(arr.begin()+i,v.back());
            v.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int> &nums) 
    {
        vector<int> v;
        solve(nums,v);
        return ans;
    }
};
