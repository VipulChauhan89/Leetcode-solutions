class Solution {
public:
    int numBusesToDestination(vector<vector<int>> &routes,int source,int target) 
    {
        if(source==target)
        {
            return 0;
        }
        int maxStop=-1;
        for(auto &route: routes)
        {
            for(auto i:route)
            {
                maxStop=max(maxStop,i);
            }
        }
        if(maxStop<target)
        {
            return -1;
        }
        int n=routes.size();
        vector<int> minBusesToReach(maxStop+1,INT_MAX);
        minBusesToReach[source]=0;
        bool flag=true;
        while(flag) 
        {
            flag=false;
            for(const auto &route:routes) 
            {
                int mn=n+1;
                for(auto i:route) 
                {
                    mn=min(mn,minBusesToReach[i]);
                }
                mn++;
                for(auto i:route) 
                {
                    if(minBusesToReach[i]>mn) 
                    {
                        minBusesToReach[i]=mn;
                        flag=true;
                    }
                }
            }
        }
        return (minBusesToReach[target]<n+1)?minBusesToReach[target]:-1;
    }
};
