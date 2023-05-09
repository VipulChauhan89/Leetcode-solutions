class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix) 
    {
        if(matrix.empty()) return {};
        int m=matrix.size(),n=matrix[0].size();
        int l=0,r=n-1,u=0,d=m-1;
        vector<int> ans;
        while(ans.size()<m*n) 
        {
            for(int j=l;j<=r && ans.size()<m*n;j++)
            {
                ans.push_back(matrix[u][j]);
            }
            u++;
            for(int i=u;i<=d && ans.size()<m*n;i++)
            {
                ans.push_back(matrix[i][r]);
            }
            r--;
            for(int j=r;j>=l && ans.size()<m*n;j--)
            {
                ans.push_back(matrix[d][j]);
            }
            d--;
            for(int i=d;i>=u && ans.size()<m*n;i--)
            {
                ans.push_back(matrix[i][l]);
            }
            l++;
        }
        return ans;
    }
};
