class Solution {
public:
    int diagonalSum(vector<vector<int>> &mat) 
    {
        int n=mat.size(),sum=0;
        int mid=n/2;
        for(int i=0;i<n;i++)
        {
            sum+=mat[i][i]+mat[n-i-1][i];
        }

        return (n%2==0)?sum:sum-mat[mid][mid];
    }
};
