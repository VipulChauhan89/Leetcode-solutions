class Solution {
public:
    int numberOfWays(string corridor)
    {
        int mod=1e9+7;
        long long z=0,o=0,t=1;
        for(auto &i:corridor)
        {
            if(i=='S')
            {
                z=o;
                swap(o,t);
            }
            else
            {
                t=(t+z)%mod;
            }
        }
        return z;
    }
};
