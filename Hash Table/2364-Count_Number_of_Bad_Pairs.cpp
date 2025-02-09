class Solution {
public:
    long long countBadPairs(vector<int> &nums) 
    {
        long long n=nums.size(),goodPairs=0;
        unordered_map<int,int> m;
        for(int i=0;i<n;i++)
        {
            int key=nums[i]-i;
            goodPairs+=m[key];
            m[key]++;
        }
        return (n*(n-1))/2-goodPairs;
    }
};
