class Solution {
public:
    vector<vector<int>> empty={{0,0,0},{0,0,0},{0,0,0}},sb={{0,0,1},{0,1,0},{1,0,0}},cb={{1,0,0},{0,1,0},{0,0,1}};
    vector<int> x={1,0,-1,0},y={0,1,0,-1};
    vector<vector<int>> mat;
    void dfs(int i,int j)
    {
        if(i<0 || i>=mat.size() || j<0 || j>=mat[0].size() || mat[i][j]==1)
        {
            return;
        }
        mat[i][j]=1;
        for(int k=0;k<4;k++)
        {
            int newi=i+x[k],newj=j+y[k];
            dfs(newi,newj);
        }
    }
    void filling(vector<vector<int>> &arr,int i)
    {
        for(int k=0;k<3;k++)
        {
            mat[i].push_back(arr[0][k]); 
            mat[i+1].push_back(arr[1][k]); 
            mat[i+2].push_back(arr[2][k]);
        }
    }
    int regionsBySlashes(vector<string> &grid) 
    {
        mat.resize(grid.size()*3);
        int ind=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                if(grid[i][j]==' ')
                {
                    filling(empty,ind);
                } 
                else if(grid[i][j]=='/')
                {
                    filling(sb,ind);
                } 
                else
                {
                    filling(cb,ind);
                } 
            }
            ind+=3;
        }
        int ans =0;
        for(int i=0;i<mat.size();i++)
        {
            for(int j=0;j<mat[0].size();j++)
            {
                if(mat[i][j]==0)
                {
                    dfs(i,j);
                    ans++;
                }
            }
        }
        return ans;
    }
};
