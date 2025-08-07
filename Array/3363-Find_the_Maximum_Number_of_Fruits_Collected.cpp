class Solution {
public:
    int maxCollectedFruits(vector<vector<int>> &fruits)
    {
        int n=fruits.size(),ans=0;
        for(int i=0;i<n;i++)
        {
            ans+=fruits[i][i];
        }
        for(int pass=0;pass<2;pass++)
        {
            if(pass==1)
            {
                for(int i=0;i<n;i++)
                {
                    for(int j=i+1;j<n;j++)
                    {
                        swap(fruits[i][j],fruits[j][i]);
                    }
                }
            }
            vector<int> previous(n,-1),current(n,-1);
            previous[n-1]=fruits[0][n-1];
            for(int r=1;r<n-1;r++)
            {
                fill(current.begin(),current.end(),-1);
                for(int i=0;i<n;i++)
                {
                    if(previous[i]<0)
                    {
                        continue;
                    }
                    if(i>0)
                    {
                        current[i-1]=max(current[i-1],previous[i]+fruits[r][i-1]);
                    }
                    if(i<n-1)
                    {
                        current[i+1]=max(current[i+1],previous[i]+fruits[r][i+1]);
                    }
                    current[i]=max(current[i],previous[i]+fruits[r][i]);
                }
                swap(previous,current);
            }
            ans+=previous[n-1];
        }
        return ans;
    }
};
