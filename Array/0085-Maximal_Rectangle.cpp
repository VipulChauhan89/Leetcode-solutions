class Solution {
public:
    int maximalRectangle(vector<vector<char>> &matrix) 
    {
        if(matrix.empty() || matrix[0].empty())
        {
            return 0;
        }
        int rows=matrix.size(),cols=matrix[0].size(),maxArea=0;
        vector<int> heights(cols+1,0);
        for(auto &row:matrix) 
        {
            for(int i=0;i<cols;i++) 
            {
                heights[i]=(row[i]=='1')?heights[i]+1:0;
            }
            int n=heights.size();
            for(int i=0;i<n;i++) 
            {
                for(int j=i,minHeight=INT_MAX;j<n;j++) 
                {
                    minHeight=min(minHeight,heights[j]);
                    int area=minHeight*(j-i+1);
                    maxArea=max(maxArea,area);
                }
            }
        }
        return maxArea;
    }
};
