class Solution {
public:
    int r,c,ans=INT_MAX;
    void dfs(vector<vector<int>> &G,int i,int j,vector<vector<bool>> &visited,vector<pair<int,int>> &S)
    {
        if(i<0 || j<0 || i>=r || j>=c || visited[i][j] || G[i][j]==0)
        {
            return;
        }
        visited[i][j]=true;
        S.push_back({i,j});
        dfs(G,i-1,j,visited,S);
        dfs(G,i+1,j,visited,S);
        dfs(G,i,j-1,visited,S);
        dfs(G,i,j+1,visited,S);
        return;
    }
    int shortestBridge(vector<vector<int>> &grid) 
    {
        r=grid.size();
        c=grid[0].size();
        vector<pair<int,int>> P,Q;
        vector<vector<bool>> visited(r,vector<bool>(c,false));
        int flag=0;
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(grid[i][j]==1 && !visited[i][j])
                {
                    if(flag==0)
                    {
                        dfs(grid,i,j,visited,P);
                        flag++;
                    }
                    else
                    {
                        dfs(grid,i,j,visited,Q);
                    }
                }
            }
        }
        for(int i=0;i<P.size();i++)
        {
            for(int j=0;j<Q.size();j++)
            {
                int x1=P[i].first,x2=Q[j].first,y1=P[i].second,y2=Q[j].second;
                int distance=abs(x1-x2)+abs(y1-y2);
                ans=min(ans,distance);
            }
        }
        return ans-1;
    }
};
