class Solution {
public:
    int minDeletionSize(vector<string> &strs)
    {
        int n=strs.size(),m=strs[0].size();
        bitset<100> isSorted=0,remove=0;
        for(int j=0;j<m;j++)
        {
            for(int i=0;i<n-1;i++)
            {
                if(isSorted[i]==0 & strs[i][j]>strs[i+1][j])
                {
                    remove[j]=1;
                    break;
                }
            }
            if(remove[j])
            {
                continue;
            }
            for(int i=0;i<n-1;i++)
            {
                isSorted[i]=isSorted[i]|(strs[i][j]<strs[i+1][j]);
            } 
        }
        return remove.count();
    }
};
