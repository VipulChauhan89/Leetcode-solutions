class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) 
    {
        if(obstacleGrid.empty() || obstacleGrid[0].empty() || obstacleGrid[0][0]==1)
        {
            return 0;
        }
        int m=obstacleGrid.size(),n=obstacleGrid[0].size();
        vector<int> previous(n,0),current(n,0);
        previous[0]=1;
        for(int i=0;i<m;i++) 
        {
            current[0]=obstacleGrid[i][0]==1?0:previous[0];
            for(int j=1;j<n;j++) 
            {
                current[j]=obstacleGrid[i][j]==1?0:current[j-1]+previous[j];
            }
            previous=current;
        }
        return previous[n-1];
    }
};
