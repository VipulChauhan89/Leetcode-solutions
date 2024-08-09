class Solution {
public:
    int magic(vector<vector<int>> &grid,int r,int c)
    {
        unordered_set<int> s;
        for(int i=r;i<r+3;i++)
        {
            for(int j=c;j<c+3;j++)
            {
                if(s.find(grid[i][j])!=s.end() || (grid[i][j]<1 || grid[i][j]>9))
                {
                    return 0;
                }
                s.insert(grid[i][j]);
            }
        }
        int sum=grid[r][c]+grid[r][c+1]+grid[r][c+2];
        for(int x=0;x<3;x++) 
        {
            if((grid[r+x][c]+grid[r+x][c+1]+grid[r+x][c+2])!=sum)
            {
                return 0;
            }   
        }
        for(int y=0;y<3;y++) 
        {
            if((grid[r][c+y]+grid[r+1][c+y]+grid[r+2][c+y])!=sum)
            {
                return 0;
            }
        }
        if((grid[r][c]+grid[r+1][c+1]+grid[r+2][c+2])!=sum)
        {
            return 0;
        } 
        if((grid[r+2][c]+grid[r+1][c+1]+grid[r][c+2])!=sum)
        {
            return 0;
        } 
        return 1;
    }
    int numMagicSquaresInside(vector<vector<int>> &grid) 
    {
        int ans=0,r=grid.size(),c=grid[0].size();
        for(int i=0;i<r-2;i++)
        {
            for(int j=0;j<c-2;j++)
            {
                ans+=magic(grid,i,j);
            }
        }
        return ans;
    }
};
