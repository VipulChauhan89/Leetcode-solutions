class Solution {
public:
    bool isValid(int r,int c,int n,int m,vector<vector<int>> &visited) 
    {
        return r>=0 && c>=0 && r<n && c<m && visited[r][c]==0;
    }
    int minCost(vector<vector<int>> &grid) 
    {
        int n=grid.size(),m=grid[0].size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        vector<vector<int>> visited(n,vector<int>(m,0));
        vector<vector<int>> directions={{0,1},{0,-1},{1,0},{-1,0}};
        pq.push({0,{0,0}});
        while(!pq.empty()) 
        {
            auto it=pq.top();
            pq.pop();
            int d=it.first,r=it.second.first,c=it.second.second;
            if(visited[r][c])
            {
                continue;
            } 
            visited[r][c]=1;
            if(r==n-1 && c==m-1) 
            {
                return d;
            }
            int dir=grid[r][c]-1,nr=r+directions[dir][0],nc=c+directions[dir][1];
            if(isValid(nr,nc,n,m,visited)) 
            {
                pq.push({d,{nr,nc}});
            }
            for(int i=0;i<4;i++) 
            {
                if(i==dir)
                {
                    continue;
                } 
                nr=r+directions[i][0];
                nc=c+directions[i][1];
                if(isValid(nr,nc,n,m,visited)) 
                {
                    pq.push({d+1,{nr,nc}});
                }
            }
        }
        return -1;
    }
};
