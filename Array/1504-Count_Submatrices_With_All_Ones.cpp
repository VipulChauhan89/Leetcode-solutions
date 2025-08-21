class Solution {
public:
    int numSubmat(vector<vector<int>> &mat)
    {
        int n=mat.size(),m=mat[0].size(),total=0;
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                if(mat[i][j])
                {
                    mat[i][j]+=mat[i][j-1];
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int mn=mat[i][j];
                for(int k=i;k>=0 && mat[k][j];k--)
                {
                    mn=min(mn,mat[k][j]);
                    total+=mn;
                }
            }
        }
        return total;
    }
};
