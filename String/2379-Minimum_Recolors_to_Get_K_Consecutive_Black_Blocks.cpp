class Solution {
public:
    int minimumRecolors(string blocks,int k) 
    {
        int n=blocks.length(),b=0,ans=INT_MAX;
        for(int i=0;i<n;i++)
        {
            if(i-k>=0 && blocks[i-k]=='B')
            {
                b--;
            }
            if(blocks[i]=='B')
            {
                b++;
            }
            ans=min(ans,k-b);
        }
        return ans;
    }
};
