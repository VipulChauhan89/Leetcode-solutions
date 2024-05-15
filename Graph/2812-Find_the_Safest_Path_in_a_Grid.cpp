class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>> &grid) 
    {
        int n=grid.size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> q;
        vector<vector<int>> dis(n,vector<int>(n,INT_MAX));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j])
                {
                    q.push({0,{i,j}});
                    dis[i][j]=0;
                }
            }
        }
        vector<vector<int>> dirs={{0,1},{0,-1},{1,0},{-1,0}};
        while(!q.empty())
        {
            int i=q.top().second.first,j=q.top().second.second,d=q.top().first;
            q.pop();
            for(auto dir:dirs)
            {
                int ni=i+dir[0],nj=j+dir[1];
                if(ni>=0 && ni<n && nj>=0 && nj<n && d+1<dis[ni][nj])
                {
                    q.push({d+1,{ni,nj}});
                    dis[ni][nj]=d+1;
                }
            }
        }
        priority_queue<pair<int,pair<int,int>>> nq;
        nq.push({dis[0][0],{0,0}});
        vector<vector<int>> vis(n,vector<int>(n,0));
        int mx=0;
        while(!nq.empty())
        {
            int safe=nq.top().first,i=nq.top().second.first,j=nq.top().second.second;
            nq.pop();
            if(i==n-1 && j==n-1)
            { 
                return safe;
            }
            for(auto dir:dirs)
            {
                int ni=i+dir[0],nj=j+dir[1];
                if(ni>=0 && ni<n && nj>=0 && nj<n && !vis[ni][nj])
                {
                    nq.push({min(safe,dis[ni][nj]),{ni,nj}});
                    vis[ni][nj]=1;
                }
            }
        }
        return mx;
    }
};
