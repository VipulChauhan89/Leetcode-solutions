class Solution {
public:
    static bool comp(vector<int> &a,vector<int> &b)
    {
        return (a[0]==b[0])?a[1]<b[1]:a[0]>b[0];
    }
    int numberOfPairs(vector<vector<int>> &points)
    {
        int n=points.size(),ans=0;
        sort(points.begin(),points.end(),comp);
        for(int i=0;i<n-1;i++)
        {
            int y1=INT_MAX,y2=points[i][1];
            for(int j=i+1;j<n;j++)
            {
                int y3=points[j][1];
                if(y3>=y2 && y1>y3)
                {
                    ans++;
                    y1=y3;
                }
            }
        }
        return ans;
    }
};
