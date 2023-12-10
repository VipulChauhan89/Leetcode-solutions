class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>> &matrix) 
    {
        int i1=0,j1;
        vector<vector<int>> ans(matrix[0].size(),vector<int>(matrix.size()));
        for(int i=0;i<matrix.size();i++)
        {
            j1=0;
            for(int j=0;j<matrix[i].size();j++)
            {
                ans[j1][i1]=matrix[i][j];
                j1++;
            }
            i1++;
        }
        return ans;
    }
};
