class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) 
    {
        int n=mat.size(),m=mat[0].size(),k=m*n;
        if(k!=r*c)
        {
            return mat;
        }
        vector<vector<int> > v(r,vector<int>(c));
        for(int i=0;i<k;i++)
        {
            v[i/c][i%c]=mat[i/m][i%m];
        }
        return v;
    }
};
