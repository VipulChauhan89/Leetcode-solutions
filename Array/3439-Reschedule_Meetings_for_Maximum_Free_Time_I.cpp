class Solution {
public:
    int maxFreeTime(int eventTime,int k,vector<int> &startTime, vector<int> &endTime)
    {
        int n=startTime.size();
        vector<int> v(n+1);
        v[0]=startTime[0];
        v[n]=eventTime-endTime[n-1];
        for(int i=1;i<n;i++)
        {
            v[i]=startTime[i]-endTime[i-1];
        }
        int i=0,j=k,mx=0,sum=0;
        for(int l=0;l<=n && l<=j;l++)
        {
            sum+=v[l];
        }
        mx=max(mx,sum);
        while(j<n)
        {
            sum-=v[i++];
            sum+=v[++j];
            mx=max(mx,sum);
        }
        return mx;
    }
};
