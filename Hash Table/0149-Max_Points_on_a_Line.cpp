class Solution {
public:
    int maxPoints(vector<vector<int>>& points) 
    {
        int maxpoints=0,n=points.size();
        for(int i=0;i<n;i++)
        {
            unordered_map<double,int> slopes;
            for(int j=0;j<n;j++)
            {
                if(j!=i)
                {
                    double slope=(points[j][0]-points[i][0])/(double)(points[j][1]-points[i][1]);
                    slopes[slope]++;
                }
            }
            int colinear=0;
            for(auto i: slopes)
            {
                colinear=max(colinear,i.second);
            }
            maxpoints=max(maxpoints,colinear+1);
        }
        return maxpoints;
    }
};
