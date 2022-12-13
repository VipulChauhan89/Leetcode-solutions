class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) 
    {
        int n=matrix.size(),m=matrix[0].size(),res=INT_MAX;
        if(n==0 && m==0)
        {
            return 0;
        }
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int mn=matrix[i-1][j];
                if(j>0)
                {
                    mn=min(mn,matrix[i-1][j-1]);
                }
                if(j<m-1)
                {
                    mn=min(mn,matrix[i-1][j+1]);
                }
                matrix[i][j]+=mn;
            }
        }
        for(int j=0;j<m;j++)
        {
            res=min(res,matrix[n-1][j]);
        }
        return res;
    }
};
