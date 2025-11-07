class Solution {
public:
    long long maxPower(vector<int> &stations,int r,int k)
    {
        int n=stations.size();
        vector<long long> diff(n+5,0),prefix(n,0);
        for(int i=0;i<n;i++)
        {
            diff[max(0,i-r)]+=stations[i];
            diff[min(n-1,i+r)+1]-=stations[i];
        }
        prefix[0]=diff[0];
        long long l=prefix[0],h=2e10;
        for(int i=1;i<n;i++)
        {
            prefix[i]=prefix[i-1]+diff[i];
            l=min(l,prefix[i]);
        }
        auto check=[&](long long mid)->bool {
            vector<long long> temp=diff;
            long long current=0,count=0;
            for(int i=0;i<n;i++)
            {
                current+=temp[i];
                if(current<mid)
                {
                    long long need=mid-current;
                    count+=need;
                    if(count>k)
                    {
                        return false;
                    }
                    current=mid;
                    if(i+2*r+1<n)
                    {
                        temp[i+2*r+1]-=need;
                    }
                }
            }
            return true;
        };
        while(l<h)
        {
            long long mid=(l+h+1)>>1;
            if(check(mid))
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
