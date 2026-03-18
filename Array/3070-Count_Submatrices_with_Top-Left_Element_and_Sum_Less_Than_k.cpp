class Solution {
public:
    int countSubmatrices(vector<vector<int>> &grid,int k)
    {
        int r=grid.size(),c=grid[0].size();
        int cnt=0,brCol=c;
        if(grid[0][0]>k)
        {
            return 0;
        }
        cnt++;
        for(int j=1;j<c;j++)
        {
            int& x=grid[0][j];
            x+=grid[0][j-1];
            if(x>k)
            {
                brCol=j;
                break;
            }
            cnt++;
        }
        for(int i=1;i<r;i++)
        {
            grid[i][0]+=grid[i-1][0];
            if(grid[i][0]>k)
            {
                break;
            }
            cnt++;
            for(int j=1;j<brCol;j++)
            {
                int& x=grid[i][j];
                x+=grid[i-1][j]+grid[i][j-1]-grid[i-1][j-1];
                if(x>k)
                {
                    brCol=j;
                    break;
                }
                cnt++;
            }
        }
        return cnt;
    }
};
