class Solution {
public:
    int swimInWater(vector<vector<int>> &grid)
    {
        int n=grid.size();
        vector<vector<bool>> visited(n,vector<bool>(n,false));
        vector<vector<int>> distance(n,vector<int>(n,1e9));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        vector<int> dx={0,0,-1,1},dy{1,-1,0,0};
        pq.push({grid[0][0],{0,0}});
        visited[0][0]=true;
        distance[0][0]=grid[0][0];
        while(!pq.empty())
        {
            auto top=pq.top();
            pq.pop();
            int tm=top.first;
            int x=top.second.first,y=top.second.second;
            distance[x][y]=tm;
            for(int i=0;i<4;i++)
            {
                int x1=x+dx[i],y1=y+dy[i];
                if(x1>=0 && x1<n && y1>=0 && y1<n)
                {
                    if(!visited[x1][y1])
                    {
                        int t=grid[x1][y1],actual=max(t,tm);
                        visited[x1][y1]=true;
                        pq.push({actual,{x1,y1}});
                    }
                }
            }
        }
        return distance[n-1][n-1];
    }
};
