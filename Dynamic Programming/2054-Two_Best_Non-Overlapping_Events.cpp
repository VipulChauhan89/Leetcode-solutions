class Solution {
public:
    int maxTwoEvents(vector<vector<int>> &events) 
    {
        int n=events.size(),ans=0,maxV=0,n2=n*2;
        vector<tuple<int,bool,int>> time(n*2);
        for(int i=0;i<n;i++)
        {
            int s=events[i][0],e=events[i][1],v=events[i][2];
            time[2*i]={s,0,v};
            time[2*i+1]={e,1,v};
        }
        sort(time.begin(),time.end());
        for(auto &[t,isEnd,v]:time)
        {
            if(isEnd)
            {
                maxV=max(maxV,v);
            } 
            else
            {
                ans=max(ans,maxV+v);
            } 
        }
        return ans;    
    }
};
