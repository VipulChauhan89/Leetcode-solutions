class Solution {
public:
    int largestSubmatrix(vector<vector<int>> &matrix)
    {
        int n=matrix.size(),m=matrix[0].size(),ans=0;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]==1)
                {
                    matrix[i][j]+=matrix[i-1][j];
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            sort(matrix[i].rbegin(),matrix[i].rend());
            for(int j=0;j<m;j++)
            {
                ans=max(ans,matrix[i][j]*(j+1));
            }
        }
        return ans;
    }
};
