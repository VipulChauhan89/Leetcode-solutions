class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>> &dimensions)
    {
        int mxArea=0,mxDiagonal=0,n=dimensions.size();
        for(int i=0;i<n;i++)
        {
            int l=dimensions[i][0],w=dimensions[i][1];
            int current=(l*l)+(w*w);
            if(current>mxDiagonal || (current==mxDiagonal && l*w>mxArea))
            {
                mxDiagonal=current;
                mxArea=l*w;
            }
        }
        return mxArea;
    }
};
