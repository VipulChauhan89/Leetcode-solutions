class Solution {
public:
    void solve(vector<int> &nums,vector<vector<int>> &ans,vector<int> &temp,map<vector<int>,int> &mp,int x)
    {
        if(temp.size()>=2)
        {
            mp[temp]++;
            if(mp[temp]>1)
            {
                return;
            }
            ans.push_back(temp);
        }
        if(x>nums.size())
        {
            return;
        }
        for(int i=x;i<nums.size();i++)
        {
            if(temp.size()>=1)
            {
                if(nums[i]<temp[temp.size()-1])
                {
                    continue;
                }
            }
            temp.push_back(nums[i]);
            solve(nums,ans,temp,mp,i+1);
            temp.pop_back();
        }
        return;
    }
    vector<vector<int>> findSubsequences(vector<int> &nums) 
    {
        vector<vector<int>> ans;
        map<vector<int>,int> mp;
        vector<int> temp;
        solve(nums,ans,temp,mp,0);
        return ans;
    }
};
