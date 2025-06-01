class Solution {
public:
    long long distributeCandies(int n,int limit) 
    {
        int mn=max(0,n-2*limit),mx=min(n,limit);
        long long w=0;
        for(int i=mn;i<=mx;i++)
        {
            int N=n-i,mnC=max(0,N-limit),mxC=min(N,limit);
            w+=(mxC-mnC+1);
        }
        return w;
    }
};
