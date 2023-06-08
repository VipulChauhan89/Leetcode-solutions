class Solution {
public:
    int countNegatives(vector<vector<int>> &grid) 
    {
        int count=0,n=grid.size(),m=grid[0].size();
        int l=0,h=n-1;
        while(h>=0 && h<n && l>=0 && l<m)
        {
            if(grid[h][l]<0)
            {
                count+=(m-l);
                h--;
            }
            else
            {
                l++;
            }
        }
        return count;
    }
};
