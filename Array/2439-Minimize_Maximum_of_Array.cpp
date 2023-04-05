class Solution {
public:
    int minimizeArrayValue(vector<int> &nums) 
    {
        long long int ans=0,s=0;
        for(int i=0;i<nums.size();i++)
        {
            s+=nums[i];
            ans=max(ans,(s+i)/(i+1));
        }
        return ans;
    }
};
