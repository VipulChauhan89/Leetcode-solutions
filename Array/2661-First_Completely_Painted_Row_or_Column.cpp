class Solution {
public:
    int firstCompleteIndex(vector<int> &arr,vector<vector<int>> &mat) 
    {
        int n=mat.size(),m=mat[0].size(),N=n*m;
        vector<int> num(N+1,-1),rowPaint(n,0),colPaint(m,0),rowPos(N),colPos(N);
        for(int i=0;i<N;i++)
        {
            num[arr[i]]=i;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int nn=mat[i][j],index=num[nn];
                rowPos[index]=i;
                colPos[index]=j;
            }
        }
        for(int i=0;i<N;i++)
        {
            int nn=arr[i],rowIdx=rowPos[num[nn]],colIdx=colPos[num[nn]];
            if(++rowPaint[rowIdx]==m || ++colPaint[colIdx]==n)
            {
                return i;
            }
        }
        return -1;
    }
};
