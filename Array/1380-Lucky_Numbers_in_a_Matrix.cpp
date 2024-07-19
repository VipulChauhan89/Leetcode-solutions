class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>> &matrix) 
    {
        int rows=matrix.size(),cols=matrix[0].size();
        vector<int> row_minimums(rows,INT_MAX),col_maximums(cols,0);
        for(int i=0;i<rows;i++) 
        {
            for(int j=0;j<cols;j++) 
            {
                int el=matrix[i][j];
                row_minimums[i]=min(row_minimums[i],el);
                col_maximums[j]=max(col_maximums[j],el);
            }
        }
        for(int i=0;i<rows;i++) 
        {
            for(int j=0;j<cols;j++) 
            {
                int el=matrix[i][j];
                if(el==row_minimums[i] && el==col_maximums[j]) 
                {
                    return {el};
                }
            }
        }
        return {};
    }
};
