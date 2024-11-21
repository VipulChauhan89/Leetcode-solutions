class Solution {
public:
    int countUnguarded(int m,int n,vector<vector<int>> &guards,vector<vector<int>> &walls) 
    {
        vector<vector<int>> visited(m,vector<int>(n,0));
        for(auto &i:guards)
        {
            visited[i[0]][i[1]]=3;
        }
        for(auto &i:walls)
        {
            visited[i[0]][i[1]]=2;
        }
        for(auto &i:guards)
        {
            int k=i[0],l=i[1];
            for(int j=k+1;j<m;j++)
            {
                if(visited[j][l]==3 || visited[j][l]==2)
                {
                    break;
                }
                visited[j][l]=1;
            }
            for(int j=k-1;j>=0;j--)
            {
                if(visited[j][l]==3 || visited[j][l]==2)
                {
                    break;
                }
                visited[j][l]=1;
            }
            for(int j=l+1;j<n;j++)
            {
                if(visited[k][j]==3 || visited[k][j]==2)
                {
                    break;
                }
                visited[k][j]=1;
            }
            for(int j=l-1;j>=0;j--)
            {
                if(visited[k][j]==3 || visited[k][j]==2)
                {
                    break;
                }
                visited[k][j]=1;
            }
        }
        int ans=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(visited[i][j]==0)
                {
                    ans++;
                }
            }
        }
        return ans;
    }
};
