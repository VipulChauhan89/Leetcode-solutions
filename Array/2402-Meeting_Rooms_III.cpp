class Solution {
public:
    int mostBooked(int n,vector<vector<int>> &meetings) 
    {
        vector<int> ans(n,0);
        vector<long long> time(n,0);
        sort(meetings.begin(),meetings.end());
        int mx=-1,id=-1;
        for(int i=0;i<meetings.size();i++)
        {
            int s=meetings[i][0],e=meetings[i][1],mn=-1;
            bool flag=false;
            long long val=1e18;
            for(int j=0;j<n;j++)
            {
                if(time[j]<val)
                {
                    val=time[j];
                    mn=j;
                }
                if(time[j]<=s)
                {
                    flag=true;
                    ans[j]++;
                    time[j]=e;
                    break;
                }
            }
            if(flag==false)
            {
                ans[mn]++;
                time[mn]+=(1ll*(e-s));
            }
        }
        for(int i=0;i<n;i++)
        {
            if(ans[i]>mx)
            {
                mx=ans[i];
                id=i;
            }
        }
        return id;
    }
};
