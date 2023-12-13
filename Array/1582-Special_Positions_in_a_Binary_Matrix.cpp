class Solution {
public:
    bool check(vector<vector<int>> &mat,int i,int j)
    {
        int n=mat.size(),m=mat[0].size();
        for(int k=0;k<n;k++)
        {
            if(k!=i && mat[k][j]==1)
            {
                return false;
            }
        }
        for(int k=0;k<m;k++)
        {
            if(k!=j && mat[i][k]==1)
            {
                return false;
            }
        }
        return true;
    }
    int numSpecial(vector<vector<int>> &mat) 
    {
        int n=mat.size(),m=mat[0].size(),total=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==1 && check(mat,i,j))
                {
                    total++;
                }
            }
        }    
        return total;  
    }
};
