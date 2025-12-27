class Solution {
public:
    int mostBooked(int n,vector<vector<int>> &meetings)
    {
        vector<long long> v(n,0);
        vector<int> count(n,0);
        sort(meetings.begin(),meetings.end());
        for(auto &i:meetings)
        {
            int start=i[0],end=i[1],roomIndex=-1;
            long long earliest=LLONG_MAX;
            bool assigned=false;
            for(int j=0;j<n;j++)
            {
                if(v[j]<earliest)
                {
                    earliest=v[j];
                    roomIndex=j;
                }
                if(v[j]<=start)
                {
                    v[j]=end;
                    count[j]++;
                    assigned=true;
                    break;
                }
            }
            if(!assigned)
            {
                v[roomIndex]+=(end-start);
                count[roomIndex]++;
            }
        }
        int ans=0,mxC=0;
        for(int i=0;i<n;i++)
        {
            if(count[i]>mxC)
            {
                mxC=count[i];
                ans=i;
            }
        }
        return ans;
    }
};
