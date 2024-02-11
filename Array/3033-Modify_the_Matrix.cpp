class Solution {
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>> &matrix) 
    {
        int n=matrix.size(),m=matrix[0].size();
        vector<vector<int>> answer=matrix;
        vector<int> max_in_column(m,numeric_limits<int>::min());
        for(int j=0;j<m;j++) 
        {
            for(int i=0;i<n;i++) 
            {
                max_in_column[j]=max(max_in_column[j],matrix[i][j]);
            }
        }
        for(int i=0;i<n;i++) 
        {
            for(int j=0;j<m;j++) 
            {
                if(answer[i][j]==-1) 
                {
                    answer[i][j]=max_in_column[j];
                }
            }
        }
        return answer;
    }
};
