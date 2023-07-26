class Solution {
public:
    int minSpeedOnTime(vector<int> &dist,double hour) 
    {
        int n=dist.size(),l=1,h=10000000;
        if(n-1>=hour)
        {
            return -1;
        }    
        while(l<=h)
        {
            int mid=l+(h-l)/2;
            double sum=0.0;
            for(int i=0;i<n-1;i++)
            {
                sum+=ceil(dist[i]/(double)mid);
            }
            sum+=(double)(dist[n-1])/mid;
            if(sum<=hour)
            {
                h=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        return h+1;
    }
};
