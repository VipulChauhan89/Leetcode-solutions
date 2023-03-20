class Solution {
public:
    pair<int,int> movement(vector<vector<int>> &grid,int row,int col)
    {
        int knightMoves[8][2]={{-2,-1},{-1,-2},{1,-2},{2,-1},{2,1},{1,2},{-1,2},{-2, 1}};
        for(int j=0;j<8;j++) 
        {
            int nextRow=row+knightMoves[j][0];
            int nextCol=col+knightMoves[j][1];
            if(nextRow>=0 && nextRow<grid.size() && nextCol>=0 && nextCol<grid[0].size() && grid[nextRow][nextCol]==grid[row][col]+1)
            {
                return {nextRow,nextCol};
            }
        }
        return {-1,-1};
    }
    bool checkValidGrid(vector<vector<int>>& grid) 
    {
        int n=grid.size(),i=0;
        pair<int,int> p{0,0};
        while(i++<n*n-1)
        {
            p=movement(grid,p.first,p.second);
            if(p.first==-1 && p.second==-1)
            {
                return false;
            }
        }
        return true;
    }
};
