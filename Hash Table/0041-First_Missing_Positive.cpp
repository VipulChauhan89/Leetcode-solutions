class Solution {
public:
    int firstMissingPositive(vector<int> &nums) 
    {
        int n=nums.size(),mx=*max_element(nums.begin(),nums.end());
        unordered_map<int,bool> m;
        for(auto &i:nums)
        {
            m[i]=true;
        }
        for(int i=1;i<mx;i++)
        {
            if(m.find(i)==m.end())
            {
                return i;
            }
        }
        return mx<0?1:mx+1;
    }
};
