class Solution {
public:
    bool hasValidPath(vector<vector<int>> &grid)
    {
        int m=grid.size(),n=grid[0].size();
        vector<vector<vector<int>>> dirs={{},{{0,-1},{0,1}},{{-1,0},{1,0}},{{0,-1},{1,0}},{{0,1},{1,0}},{{0,-1},{-1,0}},{{0,1},{-1,0}}};
        queue<pair<int,int>> q;
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        q.push({0,0});
        vis[0][0]=true;
        while(!q.empty())
        {
            auto [r,c]=q.front();
            q.pop();
            if(r==m-1 && c==n-1)
            {
                return true;
            }
            for(auto &d:dirs[grid[r][c]])
            {
                int nr=r+d[0];
                int nc=c+d[1];
                if(nr<0 || nc<0 || nr>=m || nc>=n || vis[nr][nc])
                {
                    continue;
                }
                for(auto &back:dirs[grid[nr][nc]])
                {
                    if(nr+back[0]==r && nc+back[1]==c)
                    {
                        vis[nr][nc]=true;
                        q.push({nr,nc});
                    }
                }
            }
        }
        return false;
    }
};
