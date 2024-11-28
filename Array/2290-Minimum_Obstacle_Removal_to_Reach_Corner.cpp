class Solution {
public:
    bool isValid(int r,int c,int n,int m)
    {
        if(r<0 || r>=n || c<0 || c>=m)
        {
            return false;
        }
        return true;
    }
    int minimumObstacles(vector<vector<int>> &grid) 
    {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>> direction={{0,1},{0,-1},{1,0},{-1,0}},dist(n,vector<int>(m,INT_MAX));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> q;
        q.push({grid[0][0],{0,0}});
        dist[0][0]=grid[0][0];
        dist[0][0]=grid[0][0];
        while(!q.empty())
        {
            int s=q.top().first,x=q.top().second.first,y=q.top().second.second;
            q.pop();
            if(x==n-1 && y==m-1)
            {
                return s;
            }
            for(auto &i:direction)
            {
                int new_x=x+i[0],new_y=y+i[1];
                if(isValid(new_x,new_y,n,m) && dist[new_x][new_y]>s+grid[new_x][new_y])
                {
                    dist[new_x][new_y]=s+grid[new_x][new_y];
                    q.push({dist[new_x][new_y],{new_x,new_y}});
                }
            }
        }
        return -1;
    }
};
