class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows,int cols,int rStart,int cStart) 
    {
        vector<vector<int>> direction={{0,1},{1,0},{0,-1},{-1,0}},ans;
        int steps=1,i=0,r=rStart,c=cStart;
        while(ans.size()<rows*cols)
        {
            for(int j=0;j<2;j++)
            {
                int dr=direction[i][0],dc=direction[i][1];
                for(int k=0;k<steps;k++)
                {
                    if((r>=0 && r<rows) && (c>=0 && c<cols))
                    {
                        vector<int> v={r,c};
                        ans.push_back(v);
                    }
                    r+=dr;
                    c+=dc;
                }
                i=(i+1)%4;
            }
            steps++;
        }
        return ans;
    }
};
