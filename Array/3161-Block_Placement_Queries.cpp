class Solution {
public:
    vector<bool> getResults(vector<vector<int>> &queries)
    {
        vector<bool> ans;
        int n=queries.size();
        vector<int> bar;
        map<int,pair<int,int>> mpp;
        set<pair<int,int>> s;
        bar.push_back(0);
        bar.push_back(50001);
        for(int i=0;i<n;++i)
        {
            if(queries[i][0]==1)
            {
                bar.push_back(queries[i][1]);
            }
        }
        sort(bar.begin(),bar.end());
        int sz=bar.size();
        mpp[bar[0]]={bar[0],bar[1]};
        for(int i=1;i<sz-1;++i)
        {
            mpp[bar[i]]= {bar[i-1],bar[i+1]};
        }
        mpp[bar[sz-1]]={bar[sz-2],0};
        for(int i=0;i<sz-1;++i)
        {
            s.insert({bar[i+1]-bar[i],bar[i]});
        }
        s.insert({0,bar[sz-1]});
        for(int i=n-1;i>=0;--i)
        {
            if(queries[i][0]==1)
            {
                int x=queries[i][1],xL=mpp[x].first,xR=mpp[x].second;
                s.erase({x-xL,xL});
                s.erase({xR-x,x});
                mpp[xL].second=xR;
                mpp[xR].first=xL;
                s.insert({xR-xL,xL});
            }
            else
            {
                int x=queries[i][1],dist=queries[i][2];
                if(dist>x)
                {
                    ans.push_back(false);
                    continue;
                }
                auto it=s.lower_bound({dist,0});
                bool can=false;
                for(it;it!=s.end();++it)
                {
                    if(dist+it->second<=x)
                    {
                        can=true;
                        break;
                    }
                }
                ans.push_back(can);
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
