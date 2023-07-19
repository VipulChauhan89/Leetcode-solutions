class Solution {
public:
    int maximumBeauty(vector<int> &nums,int k) 
    {
        int ans=0,sum=0;
        map<int,int> m;
        for(auto i:nums)
        {
            m[i-k]++;
            m[i+k+1]--;
        }
        for(auto i:m)
        {
            sum+=i.second;
            ans=max(ans,sum);
        }
        return ans;
    }
};
