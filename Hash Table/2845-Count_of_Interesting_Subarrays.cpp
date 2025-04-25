class Solution {
public:
    long long countInterestingSubarrays(vector<int> &nums,int modulo,int k) 
    {
        unordered_map<int,int> m;
        m[0]=1;
        long long sum=0,count=0;
        for(auto &i:nums)
        {
            if(i%modulo==k)
            {
                sum++;
            }
            int remainder=(sum-k)%modulo;
            if(remainder<0)
            {
                remainder+=modulo;
            }
            count+=m[remainder];
            m[sum%modulo]++;
        }
        return count;
    }
};
