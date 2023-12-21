class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>> &points) 
    {
        sort(points.begin(),points.end());
        int max_width=0;
        for(int i=1;i<points.size();i++)
        {
            int width=points[i][0]-points[i-1][0];
            max_width=max(max_width,width);
        }
        return max_width;
    }
};
