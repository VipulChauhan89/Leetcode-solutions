class Solution {
public:
    vector<vector<int>> generateMatrix(int n) 
    {
        vector<vector<int>> ans(n,vector<int>(n,0));
        int l=0,r=n-1,u=0,d=n-1,count=1;
        while(count<=n*n)
        {
            for(int i=l;i<=r;i++)
            {
                ans[u][i]=count++;
            }
            u++;
            for(int i=u;i<=d;i++)
            {
                ans[i][r]=count++;
            }
            r--;
            for(int i=r;i>=l;i--)
            {
                ans[d][i]=count++;
            }
            d--;
            for(int i=d;i>=u;i--)
            {
                ans[i][l]=count++;
            }
            l++;
        }
        return ans;
    }
};
