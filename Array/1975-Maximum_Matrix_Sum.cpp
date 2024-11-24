class Solution {
public:
    long long maxMatrixSum(vector<vector<int>> &matrix) 
    {
        int mn=INT_MAX;
        long long sum=0,count=0;
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                if(matrix[i][j]<0)
                {
                    count++;
                }
                int abs_value=abs(matrix[i][j]);
                mn=min(mn,abs_value);
                sum+=abs_value;
            }
        }
        if(count%2==0)
        {
            return sum;
        }
        return sum-2*mn;
    }
};
