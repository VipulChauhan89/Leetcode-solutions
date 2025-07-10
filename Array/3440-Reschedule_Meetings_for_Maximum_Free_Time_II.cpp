class Solution {
public:
    int maxFreeTime(int eventTime,vector<int> &startTime,vector<int> &endTime)
    {
        int n=startTime.size(),mx=0,l=0;
        if(n==0)
        {
            return eventTime;
        }
        vector<int> v(n+1,0),lr(n+1,0);
        v[0]=startTime[0];
        v[n]=eventTime-endTime[n-1];
        for(int i=1;i<n;i++)
        {
            v[i]=startTime[i]-endTime[i-1];
        }
        for(int i=n-1;i>=0;i--)
        {
            lr[i]=max(lr[i+1],v[i+1]);
        }
        for(int i=1;i<=n;i++)
        {
            int duration=endTime[i-1]-startTime[i-1];
            if(l>=duration || lr[i]>=duration)
            {
                int merged=v[i-1]+v[i]+duration;
                mx=max(mx,merged);
            }
            mx=max(mx,v[i-1]+v[i]);
            l=max(l,v[i-1]);
        }
        return mx;
    }
};
