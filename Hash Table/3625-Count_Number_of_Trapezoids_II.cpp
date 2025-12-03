class Solution {
public:
    int countTrapezoids(vector<vector<int>> &points)
    {
        int n=points.size(),inf=1e9+7;
        unordered_map<float,vector<float>> slopeTointercept;
        unordered_map<int,vector<float>> midpointToslope;
        for(int i=0;i<n-1;i++)
        {
            int xi=points[i][0],yi=points[i][1];
            for(int j=i+1;j<n;j++)
            {
                int xj=points[j][0],yj=points[j][1],dx=(xi-xj),dy=(yi-yj);
                float slope,intercept;
                if(xi==xj)
                {
                    slope=inf;
                    intercept=xi;
                }
                else
                {
                    slope=(float)dy/dx;
                    intercept=((float)yi*dx-xi*dy)/dx;
                }
                int midpoint=(xi+xj)*10000+(yi+yj);
                slopeTointercept[slope].push_back(intercept);
                midpointToslope[midpoint].push_back(slope);
            }
        }
        int ans=0;
        for(auto &[slope,intercept]:slopeTointercept)
        {
            if(intercept.size()==1)
            {
                continue;
            }
            map<float,int> sameintercept;
            for(float val:intercept)
            {
                sameintercept[val]++;
            }
            int sum=0;
            for(auto &[_,cnt]:sameintercept)
            {
                ans+=sum*cnt;
                sum+=cnt;
            }
        }
        for(auto &[midpoint,slope]:midpointToslope)
        {
            if(slope.size()==1)
            {
                continue;
            }
            map<float,int> sameslope;
            for(float val:slope)
            {
                sameslope[val]++;
            }
            int sum=0;
            for(auto &[_,cnt]:sameslope)
            {
                ans-=sum*cnt;
                sum+=cnt;
            }
        }
        return ans;
    }
};
