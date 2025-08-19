class Solution {
public:
    long long zeroFilledSubarray(vector<int> &nums)
    {
        long long ans=0,current=0;
        for(auto &i:nums)
        {
            if(i==0)
            {
                current++;
                ans+=current;
            }
            else
            {
                current=0;
            }
        }
        return ans;
    }
};
