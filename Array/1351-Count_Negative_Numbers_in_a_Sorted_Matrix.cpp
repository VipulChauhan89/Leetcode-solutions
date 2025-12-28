class Solution {
public:
    int countNegatives(vector<vector<int>> &grid)
    {
        int n=grid.size(),m=grid[0].size(),sum=0;
        vector<int> c(n);
        for(int i=0;i<n;i++)
        {
            c[i]=grid[i][0];
        }
        int i_m=upper_bound(c.begin(),c.end(),0,greater<int>())-c.begin();
        for(int i=0;i<i_m;i++)
        {
            sum+=m-(upper_bound(grid[i].begin(),grid[i].end(),0,greater<int>())-grid[i].begin());
        }
        sum+=(n-i_m)*m;
        return sum;
    }
};
