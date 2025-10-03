class Solution {
public:
    bool valid(int n,int m,int r,int c)
    {
        return (min(r,c)>=0 && r<n && c<m);
    }
    using T=pair<int,pair<int,int>>;
    int trapRainWater(vector<vector<int>> &heightMap)
    {
        int n=heightMap.size(),m=heightMap[0].size(),water=0;
        priority_queue<T,vector<T>,greater<T>> pq;
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        vector<pair<int,int>> dir={{0,1},{0,-1},{1,0},{-1,0}};
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0 || i==n-1 || j==0 || j==m-1)
                {
                    pq.push({heightMap[i][j],{i,j}});
                    visited[i][j]=true;
                }
            }
        }
        while(!pq.empty())
        {
            T p=pq.top();
            pq.pop();
            for(auto &i:dir)
            {
                int nr=p.second.first+i.first,nc=p.second.second+i.second;
                if(valid(n,m,nr,nc) && !visited[nr][nc])
                {
                    visited[nr][nc]=true;
                    if(heightMap[nr][nc]<p.first)
                    {
                        water+=p.first-heightMap[nr][nc];
                    }
                    pq.push({max(p.first,heightMap[nr][nc]),{nr,nc}});
                }
            }
        }
        return water;
    }
};
