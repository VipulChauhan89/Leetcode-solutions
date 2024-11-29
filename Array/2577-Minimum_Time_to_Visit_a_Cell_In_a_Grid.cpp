class Solution {
public:
    int minimumTime(vector<vector<int>> &grid) 
    {
        int m=grid.size(),n=grid[0].size();
        if(grid[0][1]>1 && grid[1][0]>1)
        {
            return -1;
        }
        vector<vector<int>> ans(m,vector<int>(n,INT_MAX));
        vector<pair<int,int>> direc={{1,0},{0,1},{-1,0},{0,-1}};
        priority_queue<pair<int,pair<int,int>>> pq;
        pq.push({0,{0,0}});
        while(pq.size()) 
        {
            auto it=pq.top();
            pq.pop();
            for(auto e:direc) 
            {
                int x=it.second.first+e.first,y=it.second.second+e.second;
                if(x<0 || y<0 || x>=m || y>=n)
                {
                    continue;
                }
                int time=-it.first+1;
                if(time<grid[x][y])
                {
                    time=grid[x][y]+((grid[x][y]-time)&1);
                }
                if(time<ans[x][y]) 
                {
                    ans[x][y]=time;
                    pq.push({-time,{x,y}});
                }
            }
        }
        return ans[m-1][n-1];
    }
};
