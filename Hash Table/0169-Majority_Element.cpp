class Solution {
public:
    int majorityElement(vector<int> &nums) 
    {
        int n=nums.size(),ans=0;
        unordered_map<int,int> m;
        for(auto i:nums)
        {
            m[i]++;
        }
        for(auto &i:m)
        {
            if(i.second>n/2)
            {
                ans=i.first;
                break;
            }
        }
        return ans;
    }
};
