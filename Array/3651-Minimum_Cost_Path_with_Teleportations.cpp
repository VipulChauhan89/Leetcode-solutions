class Solution{
public:
    int minCost(vector<vector<int>>& grid,int k){
        int m=grid.size(),n=grid[0].size();
        const long long INF=1e30;
        vector<pair<int,int>> cells;
        cells.reserve(m*n);
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                cells.push_back({grid[i][j],i*n+j});
            }
        }
        sort(cells.begin(),cells.end(),[](auto&a,auto&b){
            return a.first!=b.first?a.first>b.first:a.second>b.second;
        });
        vector<long long> dist(m*n,INF);
        dist[0]=0;
        long long best=INF;
        for(int step=0;step<=k;step++)
        {
            for(int i=0;i<m;i++)for(int j=0;j<n;j++)
            {
                int idx=i*n+j;
                if(dist[idx]>=INF)
                {
                    continue;
                }
                if(j+1<n)
                {
                    dist[idx+1]=min(dist[idx+1],dist[idx]+grid[i][j+1]);
                }
                if(i+1<m)
                {
                    dist[idx+n]=min(dist[idx+n],dist[idx]+grid[i+1][j]);
                }
            }
            best=min(best,dist[m*n-1]);
            if(step==k)
            {
                break;
            }
            vector<long long> next(m*n,INF);
            long long move=INF;
            for(int p=0,q;p<cells.size();p=q)
            {
                q=p;
                long long gmin=INF;
                while(q<cells.size()&&cells[q].first==cells[p].first)
                {
                    gmin=min(gmin,dist[cells[q++].second]);
                }
                move=min(move,gmin);
                for(int i=p;i<q;i++)
                {
                    next[cells[i].second]=move;
                }
            }
            dist.swap(next);
        }
        return best>=INF?-1:(int)best;
    }
};
