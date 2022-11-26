class Solution {
public:
    int missingNumber(vector<int>& nums) 
    {
        unsigned long int sum=0;
        int n=nums.size();
        for(auto i:nums)
        {
            sum+=i;
        }
        return (n*(n+1)*0.5)-sum;
    }
};
