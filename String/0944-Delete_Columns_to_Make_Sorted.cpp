class Solution {
public:
    int minDeletionSize(vector<string> &strs)
    {
        int rows=strs.size(),cols=strs[0].size(),del=0;
        for(int i=0;i<cols;i++)
        {
            for(int j=0;j<rows-1;j++)
            {
                if(strs[j][i]>strs[j+1][i])
                {
                    del++;
                    break;
                }
            }
        }
        return del;
    }
};
