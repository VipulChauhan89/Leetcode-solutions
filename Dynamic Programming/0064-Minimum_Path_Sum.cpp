class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) 
    {
        int m=grid.size(),n=grid[0].size();
        vector<int> previous(m,grid[0][0]);
        vector<int> current(m,0);
        for(int i=1;i<m;i++)
        {
            previous[i]=previous[i-1]+grid[i][0];
        }
        for(int j=1;j<n;j++) 
        { 
            current[0]=previous[0]+grid[0][j]; 
            for(int i=1;i<m;i++)
            {
                current[i]=min(current[i-1],previous[i])+grid[i][j];
            }
            swap(previous,current); 
        }
        return previous[m-1];
    }
};
