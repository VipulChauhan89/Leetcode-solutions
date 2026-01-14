class Solution {
public:
    double separateSquares(vector<vector<int>> &squares)
    {
        vector<tuple<long long,int,long long,long long>> events;
        for(auto &s:squares)
        {
            long long x=s[0],y=s[1],l=s[2];
            events.push_back({y,1,x,x+l});
            events.push_back({y+l,-1,x,x+l});
        }
        sort(events.begin(),events.end());
        vector<pair<long long,long long>> active;
        long long prev_y=get<0>(events[0]),total_area=0;
        vector<tuple<long long,long long,long long>> slices;
        auto union_width=[&](vector<pair<long long,long long>> &v)
        {
            sort(v.begin(),v.end());
            long long w=0,right=-1e18;
            for(auto &p:v)
            {
                if(p.first>right)
                {
                    w+=p.second-p.first;
                    right=p.second;
                }
                else if(p.second>right)
                {
                    w+=p.second-right;
                    right=p.second;
                }
            }
            return w;
        };
        for(auto &e:events)
        {
            long long y=get<0>(e);
            int t=get<1>(e);
            long long xl=get<2>(e),xr=get<3>(e);
            if(y>prev_y && !active.empty())
            {
                long long h=y-prev_y,w=union_width(active);
                slices.push_back({prev_y,h,w});
                total_area+=h*w;
            }
            if(t==1)
            {
                active.push_back({xl,xr});
            }
            else
            {
                active.erase(find(active.begin(),active.end(),make_pair(xl,xr)));
            }
            prev_y=y;
        }
        double half=total_area/2.0,cur=0;
        for(auto &s:slices)
        {
            double sy=get<0>(s),h=get<1>(s),w=get<2>(s);
            if(cur+h*w>=half)
            {
                return sy+(half-cur)/w;
            }
            cur+=h*w;
        }
        return (double)prev_y;
    }
};
