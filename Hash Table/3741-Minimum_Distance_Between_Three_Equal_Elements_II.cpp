class Solution {
public:
    int minimumDistance(vector<int> &nums)
    {
        unordered_map<int,vector<int>> mp;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            mp[nums[i]].push_back(i);
        }
        int mini=INT_MAX;
        for(auto &it:mp)
        {
            vector<int> &temp=it.second;
            int m=temp.size();
            if(m>=3)
            {
                for(int i=0;i<m-2;i++)
                {
                    int a=temp[i],b=temp[i+1],c=temp[i+2];
                    int diff=2*(c-a);
                    mini=min(mini,diff);
                }
            }
        }
        return mini==INT_MAX?-1:mini;
    }
};
