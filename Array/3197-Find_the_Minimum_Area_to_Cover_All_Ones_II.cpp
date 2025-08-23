class Solution {
public:
    int rectArea(vector<vector<int>> &grid,int r1,int r2,int c1,int c2)
    {
        int n=grid.size(),m=grid[0].size();
        int minr=n,maxr=-1,minc=m,maxc=-1;
        for(int i=r1;i<=r2;i++)
        {
            for(int j=c1;j<=c2;j++)
            {
                if(grid[i][j])
                {
                    minr=min(minr,i);
                    maxr=max(maxr,i);
                    minc=min(minc,j);
                    maxc=max(maxc,j);
                }
            }
        }
        if(maxr==-1)
        {
            return INT_MAX;
        }
        return (maxr-minr+1)*(maxc-minc+1);
    }
    int minimumSum(vector<vector<int>> &grid)
    {
        int n=grid.size(),m=grid[0].size();
        int ans=INT_MAX;
        for(int i=0;i<m-2;i++)
        {
            for(int j=i+1;j<m-1;j++)
            {
                int a=rectArea(grid,0,n-1,0,i);
                int b=rectArea(grid,0,n-1,i+1,j);
                int c=rectArea(grid,0,n-1,j+1,m-1);
                if(a!=INT_MAX && b!=INT_MAX && c!=INT_MAX)
                {
                    ans=min(ans,a+b+c);
                }
            }
        }
        for(int i=0;i<n-2;i++)
        {
            for(int j=i+1;j<n-1;j++)
            {
                int a=rectArea(grid,0,i,0,m-1);
                int b=rectArea(grid,i+1,j,0,m-1);
                int c=rectArea(grid,j+1,n-1,0,m-1);
                if(a!=INT_MAX && b!=INT_MAX && c!=INT_MAX)
                {
                    ans=min(ans,a+b+c);
                }
            }
        }
        for(int i=0;i<m-1;i++)
        {
            int left=rectArea(grid,0,n-1,0,i);
            if(left==INT_MAX)
            {
                continue;
            } 
            for(int j=0;j<n-1;j++)
            {
                int a=rectArea(grid,0,j,i+1,m-1);
                int b=rectArea(grid,j+1,n-1,i+1,m-1);
                if(a!=INT_MAX && b!=INT_MAX)
                {
                    ans=min(ans,left+a+b);
                }
            }
        }
        for(int i=0;i<m-1;i++)
        {
            int right=rectArea(grid,0,n-1,i+1,m-1);
            if(right==INT_MAX)
            {
                continue;
            }
            for(int j=0;j<n-1;j++)
            {
                int a=rectArea(grid,0,j,0,i);
                int b=rectArea(grid,j+1,n-1,0,i);
                if(a!=INT_MAX && b!=INT_MAX)
                {
                    ans=min(ans,right+a+b);
                }
            }
        }
        for(int i=0;i<n-1;i++)
        {
            int top=rectArea(grid,0,i,0,m-1);
            if(top==INT_MAX)
            {
                continue;
            }
            for(int j=0;j<m-1;j++)
            {
                int a=rectArea(grid,i+1,n-1,0,j);
                int b=rectArea(grid,i+1,n-1,j+1,m-1);
                if(a!=INT_MAX && b!=INT_MAX)
                {
                    ans=min(ans,top+a+b);
                }
            }
        }
        for(int i=0;i<n-1;i++)
        {
            int bottom=rectArea(grid,i+1,n-1,0,m-1);
            if(bottom==INT_MAX)
            {
                continue;
            }
            for(int j=0;j<m-1;j++)
            {
                int a=rectArea(grid,0,i,0,j);
                int b=rectArea(grid,0,i,j+1,m-1);
                if(a!=INT_MAX && b!=INT_MAX)
                {
                    ans=min(ans,bottom+a+b);
                }
            }
        }
        return ans;
    }
};

