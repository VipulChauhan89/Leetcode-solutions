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
                    matrix[i][j]=matrix[i-1][j]+1;
                }
            }
        }
        for(auto i:matrix)
        {
            sort(i.begin(),i.end());
            for(int j=m-1,w=1;j>=0 && i[j]>0;j--,w++)
            {
                int area=i[j]*w;
                ans=max(ans,area);
            }
        }
        return ans;
    }
};
