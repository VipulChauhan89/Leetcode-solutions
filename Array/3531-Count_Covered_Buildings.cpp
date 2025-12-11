class Solution {
public:
    int countCoveredBuildings(int n,vector<vector<int>> &buildings)
    {
        int ans=0;
        vector<int> minx(n+1,n+1),maxx(n+1,0),miny(n+1,n+1),maxy(n+1,0);
        for(auto i:buildings)
        {
            int x=i[0],y=i[1];
            minx[y]=min(minx[y],x);
            maxx[y]=max(maxx[y],x);
            miny[x]=min(miny[x],y);
            maxy[x]=max(maxy[x],y);
        }
        for(auto i:buildings)
        {
            int x=i[0],y=i[1];
            if(minx[y]<x && x<maxx[y] && miny[x]<y && y<maxy[x])
            {
                ans+=1;
            }
        }
        return ans;
    }
};
