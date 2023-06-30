class Solution {
public:
    int n,m;
    int d[5]={0,1,0,-1,0};
    bool dfs(vector<vector<int>> &vis,vector<vector<int>> &v,int i,int j)
    {
        vis[i][j]=1;
        if(i==n-1)
        {
            return true;
        }
        bool ans=false;
        for(int k=0;k<4;k++)
        {
            int ni=i+d[k];
            int nj=j+d[k+1];
            if(ni>=0 && nj>=0 && ni<n && nj<m && !vis[ni][nj] && !v[ni][nj])
            {
                ans|=dfs(vis,v,ni,nj);
            }
        }
        return ans;
    }
    int latestDayToCross(int row,int col, vector<vector<int>> &cells) 
    {
        int l=0,r=cells.size()-1,day=0;
        n=row;
        m=col;
        while(l<=r)
        {
            int mid=(l+r)/2;
            vector<vector<int>> v(row,vector<int>(col,0));
            for(int i=0;i<=mid;i++)
            {
                v[cells[i][0]-1][cells[i][1]-1]=1;
            }
            vector<vector<int>> vis(row,vector<int>(col,0));
            bool ans=false;
            for(int i=0;i<col;i++)
            {
                if(vis[0][i]==0 && v[0][i]==0)
                {
                   ans |= dfs(vis,v,0,i);
                }
            }
            if(ans)
            {
                day=mid;
                l=mid+1;
            }
            else
            {
                r=mid-1;
            }
        }
        return day+1;
    }
};
