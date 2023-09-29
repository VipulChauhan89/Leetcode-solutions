class Solution {
public:
    bool isMonotonic(vector<int>& nums) 
    {
        int n=nums.size();
        vector<int> v=nums;
        sort(v.begin(),v.end());
        bool increase=true,decrease=true;
        for(int i=0;i<n;i++)
        {
            if(nums[i]!=v[i])
            {
                increase=false;
            }
            if(nums[n-i-1]!=v[i])
            {
                decrease=false;
            }
        }
        return increase || decrease;
    }
};
