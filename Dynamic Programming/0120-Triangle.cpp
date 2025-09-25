class Solution {
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        for(int i=triangle.size()-2;i>=0;i--)
        {
            for(int j=0;j<triangle[i].size();j++)
            {
                int below=triangle[i+1][j],belowRight=triangle[i+1][j+1];
                triangle[i][j]+=min(below,belowRight);
            }
        }
        return triangle[0][0];
    }
};
