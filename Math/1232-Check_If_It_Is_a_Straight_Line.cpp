class Solution {
public:
    bool checkStraightLine(vector<vector<int>> &coordinates) 
    {
        int n=coordinates.size();
        int x=coordinates[1][0]-coordinates[0][0],y=coordinates[1][1]-coordinates[0][1];
        for(int i=2;i<n;i++)
        {   
            int x1=coordinates[i][0]-coordinates[0][0],y1=coordinates[i][1]-coordinates[0][1];
            if(x1*y!=y1*x)
            {
                return false;
            }
        }
        return true;
    }
};
