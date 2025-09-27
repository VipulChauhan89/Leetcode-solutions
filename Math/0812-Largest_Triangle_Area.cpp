class Solution {
public:
    double largestTriangleArea(vector<vector<int>> &points)
    {
        double ans=0;
        int n=points.size();
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                for(int k=j+1;k<n;k++)
                {
                    auto &a=points[i],&b=points[j],&c=points[k];
                    ans=max(ans,0.5*abs(a[0]*(b[1]-c[1])+b[0]*(c[1]-a[1])+c[0]*(a[1]-b[1])));
                }
            }
        }
        return ans;
    }
};
