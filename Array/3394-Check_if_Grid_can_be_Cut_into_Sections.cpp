class Solution {
public:
    bool checkValidCuts(int n,vector<vector<int>> &rectangles) 
    {
        int sz=rectangles.size();
        vector<pair<int,int>> x(sz),y(sz),mergedx,mergedy;
        for(int i=0;i<sz;i++) 
        {
            x[i]={rectangles[i][0],rectangles[i][2]};
            y[i]={rectangles[i][1],rectangles[i][3]};
        }
        sort(x.begin(),x.end());
        sort(y.begin(),y.end());
        mergedx.push_back({x[0].first,x[0].second});
        mergedy.push_back({y[0].first,y[0].second});
        for(int i=1;i<sz;i++)
        {
            if(mergedx.back().second>x[i].first)
            {
                pair<int,int> p=mergedx.back();
                mergedx.pop_back();
                mergedx.push_back({min(p.first,x[i].first),max(p.second,x[i].second)});
            }
            else
            {
                mergedx.push_back({x[i].first,x[i].second});
            }
        }
        for(int i=1;i<sz;i++)
        {
            if(mergedy.back().second>y[i].first)
            {
                pair<int,int> p=mergedy.back();
                mergedy.pop_back();
                mergedy.push_back({min(p.first,y[i].first),max(p.second,y[i].second)});
            }
            else
            {
                mergedy.push_back({y[i].first,y[i].second});
            }
        }
        return (mergedx.size()>=3 || mergedy.size()>=3); 
    }
};
