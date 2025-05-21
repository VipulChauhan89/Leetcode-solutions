class Solution {
public:
    void setZeroes(vector<vector<int>> &matrix) 
    {
        unordered_set<int> c,r;
        int n=matrix.size(),m=matrix[0].size();
        r.reserve(n),c.reserve(m);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]==0)
                {
                    if(r.count(i)==0)
                    {
                        r.insert(i);
                    } 
                    if(c.count(j)==0)
                    {
                        c.insert(j);
                    } 
                }
            }
        }
        for(auto &i:r)
        {
            for(int j=0;j<m;j++)
            {
                matrix[i][j]=0;
            }
        }
        for(auto &j:c)
        {
            for(int i=0;i<n;i++)
            {
                matrix[i][j]=0;
            }
        }
    }
};
