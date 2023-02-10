class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) 
    {
        int n=grid.size(),dist=0,size,drow[]={0,-1,0,1},dcol[]={-1,0,1,0};
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    q.push({i, j});
                }
            }
        }
        if(q.size()==n*n)
        {
            return -1;
        }
        while(!q.empty())
        {
            size=q.size();
            dist++;
            while(size--)
            {
                int r=q.front().first,c=q.front().second;
                q.pop();
                for(int i=0;i<4;i++)
                {
                    int nrow=r+drow[i],ncol=c+dcol[i];
                    if(nrow>=0 && ncol>=0 && nrow<n && ncol<n && grid[nrow][ncol]==0)
                    {
                        grid[nrow][ncol]=1;
                        q.push({nrow,ncol});
                    } 
                }
            }
        }
        return dist-1;
    }
};
