class Solution {
public:
    int largestRectangleArea(vector<int> &heights)
    {
        stack<int> st;
        heights.push_back(0);
        int maxArea=0;
        for(int i=0;i<heights.size();i++)
        {
            while(!st.empty() && heights[st.top()]>heights[i])
            {
                int h=heights[st.top()];
                st.pop();
                int width=st.empty()?i:i-st.top()-1;
                maxArea=max(maxArea,h*width);
            }
            st.push(i);
        }
        heights.pop_back();
        return maxArea;
    }
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        if(matrix.empty())
        {
            return 0;
        }
        int rows=matrix.size(),cols=matrix[0].size(),ans=0;
        vector<int> height(cols,0);
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                if(matrix[i][j]=='1')
                {
                    height[j]+=1;
                }
                else
                {
                    height[j]=0;
                }
            }
            ans=max(ans,largestRectangleArea(height));
        }
        return ans;
    }
};
