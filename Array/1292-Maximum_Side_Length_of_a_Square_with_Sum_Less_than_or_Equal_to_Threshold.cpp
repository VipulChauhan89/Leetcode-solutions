class Solution {
public:
    int maxSideLength(vector<vector<int>> &mat,int threshold)
    {
        int m=mat.size(),n=mat[0].size();
        vector<vector<int>> pref(m+1,vector<int>(n+1,0));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                pref[i+1][j+1]=pref[i+1][j]+pref[i][j+1]-pref[i][j]+mat[i][j];
            }
        }
        auto check = [&](int x)
        {
            for(int i=0;i<=m-x;i++)
            {
                for(int j=0;j<=n-x;j++)
                {
                    int sum=pref[i+x][j+x]-pref[i][j+x]-pref[i+x][j]+pref[i][j];
                    if(sum<=threshold)
                    {
                        return true;
                    }
                }
            }
            return false;
        };
        int low=1,high=min(m,n);
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(check(mid))
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        return high;
    }
};
