class Solution {
public:
    long long maxMatrixSum(vector<vector<int>> &matrix)
    {
        long long sum=0;
        int minAbs=INT_MAX;
        bool negOdd=0;
        for(auto &row:matrix)
        {
            for(auto &x:row)
            {
                const bool neg=x<0;
                const int absX=(1-neg*2)*x;
                minAbs=min(minAbs,absX);
                sum+=absX;
                negOdd^=neg;
            }
        }
        return sum-2*(negOdd)*minAbs;
    }
};
