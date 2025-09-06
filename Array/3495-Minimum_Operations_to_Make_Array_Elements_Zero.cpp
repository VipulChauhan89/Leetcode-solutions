class Solution {
public:
    long long step(long long n)
    {
        if(n<=0)
        {
            return 0;
        }
        long long ans=0,base=1,stp=1;
        while(base<=n)
        {
            long long count=min(n,(base*4)-1)-base+1;
            ans+=count*stp;
            base*=4;
            stp++;
        }
        return ans;
    }
    long long minOperations(vector<vector<int>> &queries)
    {
        long long ans=0;
        for(auto &i:queries)
        {
            ans+=(step(i[1])-step(i[0]-1)+1)/2;
        }
        return ans;
    }
};
