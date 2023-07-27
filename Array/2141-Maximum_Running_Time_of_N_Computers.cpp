class Solution {
public:
    long long maxRunTime(int n,vector<int> &batteries) 
    {
        long long l=1,h=accumulate(batteries.begin(),batteries.end(),0LL)/n;
        while(l<h)
        {
            long long mid=(h+l+1)/2,time=0;
            for(auto i:batteries)
            {
                time+=min((long long)i,mid);
            }
            if(mid*n<=time)
            {
                l=mid;
            }
            else
            {
                h=mid-1;
            }
        }
        return l;
    }
};
