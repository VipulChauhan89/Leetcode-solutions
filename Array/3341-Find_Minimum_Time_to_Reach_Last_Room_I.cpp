class Solution {
public:
    int minTimeToReach(vector<vector<int>> &moveTime) 
    {
        int m=moveTime.size(),n=moveTime[0].size();
        vector<vector<int>> dist(m,vector<int>(n,INT_MAX));
        dist[0][0]=0;
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<>> pq;
        pq.push({0,0,0});
        vector<vector<int>> dirs={{1,0},{-1,0},{0,1},{0,-1}};
        while(!pq.empty()) 
        {
            auto [time,x,y]=pq.top();
            pq.pop();
            if(x==m-1 && y==n-1)
            {
                return time;
            }
            for(auto &i:dirs) 
            {
                int nx=x+i[0],ny=y+i[1];
                if(nx>=0 && nx<m && ny>=0 && ny<n) 
                {
                    int waitTime=max(0,moveTime[nx][ny]-time),arriveTime=time+1+waitTime;
                    if(arriveTime<dist[nx][ny]) 
                    {
                        dist[nx][ny]=arriveTime;
                        pq.push({arriveTime,nx,ny});
                    }
                }
            }
        }
        return -1;
    }
};
