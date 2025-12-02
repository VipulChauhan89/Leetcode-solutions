class Solution {
public:
    int countTrapezoids(vector<vector<int>> &points)
    {
        int mod=1e9+7;
        unordered_map<int,int> m;
        for(auto &i:points)
        {
            m[i[1]]+=1;
        }
        long long sum=0,ans=0;
        for(auto &i:m)
        {
            long long V=(long long)i.second*(i.second-1)/2;
            ans+=sum*V;
            ans%=mod;
            sum+=V;
            sum%=mod;
        }
        return ans;
    }
};
