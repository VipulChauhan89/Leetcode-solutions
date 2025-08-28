class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>> &grid)
    {
        vector<int> diagonal(10);
        int n=grid.size();
        for(int i=n-2;i>0;i--)
        {
            for(int j=0;j<n-i;j++)
            {
                diagonal[j]=grid[j][j+i];
            }
            sort(diagonal.begin(),diagonal.begin()+(n-i));
            for(int j=0;j<n-i;j++)
            {
                grid[j][j+i]=diagonal[j];
            }
        }
        for(int i=0;i<n-1;i++)
        {
            for(int j=0;j<n-i;j++)
            {
                diagonal[j]=grid[j+i][j];
            }
            sort(diagonal.begin(),diagonal.begin()+(n-i),greater<int>());
            for(int j=0;j<n-i;j++)
            {
                grid[j+i][j]=diagonal[j];
            }
        }
        return grid;
    }
};
