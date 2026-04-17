class Solution {
public:
    int minMirrorPairDistance(vector<int> &nums)
    {
        int ans=INT_MAX,i=0;
        unordered_map<int,int> seen;
        for(auto &n:nums)
        {
            int r;
            if(seen.count(n))
            {
                ans=min(ans,i-seen[n]);
            }
            for(r=0;n;n/=10)
            {
                r=r*10+(n%10);
            }
            seen[r]=i++;
        }
        return -(ans==INT_MAX)|ans;
    }
};
