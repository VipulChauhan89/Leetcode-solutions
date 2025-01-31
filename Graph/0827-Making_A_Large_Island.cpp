class Solution {
public:
    void dfs(int r,int c,vector<vector<int>> &visited, vector<vector<int>> &grid,int &temp,int &idx)
    {
        int n=grid.size();
        if(r<0 || c<0 || r>=n || c>=n || grid[r][c]==0 || visited[r][c])
        {
            return;
        }
        visited[r][c]=1;
        temp++;
        grid[r][c]=idx;
        vector<int> dx={0,0,-1,1},dy={-1,1,0,0};
        for(int i=0;i<4;i++)
        {
            int nrow=dx[i]+r,ncol=dy[i]+c;
            dfs(nrow,ncol,visited,grid,temp,idx);            
        }
    }
    int largestIsland(vector<vector<int>> &grid) 
    {
        int n=grid.size(),idx=-1,ans=0;
        queue<pair<int,int>> q;
        vector<vector<int>> visited(n,vector<int>(n));
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==0)
                {
                    q.push({i,j});
                } 
            }
        }
        if(q.empty())
        {
            return n*n;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                int temp=0;
                if(!visited[i][j] && grid[i][j]!=0)
                {
                    dfs(i,j,visited,grid,temp,idx);
                    mp[idx]=temp;
                    idx--;
                }
            }
        }
        while(!q.empty())
        {
            auto[r,c]=q.front();
            q.pop();
            vector<int>dx={0,0,-1,1},dy={-1,1,0,0};
            int temp=1;
            unordered_set<int> st;
            for(int i=0;i<4;i++)
            {
                int nrow=dx[i]+r,ncol=dy[i]+c;
                if(nrow>=0 && ncol>=0 && nrow<n && ncol<n && grid[nrow][ncol]!=0)
                {
                    st.insert(grid[nrow][ncol]);
                }
            }
            for(auto &i:st)
            {
                temp+=mp[i];
            } 
            ans=max(ans,temp);
        }

        return  (ans==0)?1:ans;
    }
};
