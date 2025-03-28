class Solution {
public:
    vector<int> maxPoints(vector<vector<int>> &grid,vector<int> &queries) 
    {
        int n=grid.size(),m=grid[0].size(),k=queries.size(),mxPoints=0;
        vector<pair<int,int>> q;
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        vector<int> ans(k);
        vector<vector<int>> directions={{0,1},{0,-1},{1,0},{-1,0}};
        pq.push({grid[0][0],0,0});
        visited[0][0]=true;
        for(int i=0;i<k;i++)
        {
            q.push_back({queries[i],i});
        }
        sort(q.begin(),q.end());
        for(int i=0;i<k;i++)
        {
            int value=q[i].first,index=q[i].second;
            while(!pq.empty() && pq.top()[0]<value)
            {
                auto current=pq.top();
                pq.pop();
                int row=current[1],col=current[2];
                mxPoints++;
                for(auto &j:directions)
                {
                    int newRow=row+j[0],newCol=col+j[1];
                    if(newRow>=0 && newCol>=0 && newRow<n && newCol<m && !visited[newRow][newCol])
                    {
                        pq.push({grid[newRow][newCol],newRow,newCol});
                        visited[newRow][newCol]=true;
                    }
                }
            }
            ans[index]=mxPoints;
        }
        return ans;
    }
};
