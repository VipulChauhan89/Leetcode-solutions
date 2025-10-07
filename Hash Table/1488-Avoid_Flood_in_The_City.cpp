class Solution {
public:
    vector<int> avoidFlood(vector<int> &rains)
    {
        int n=rains.size();
        vector<int> ans(n,1);
        unordered_map<int,int> rainDay;
        rainDay.reserve(n);
        set<int> dry;
        for(int i=0;i<n;i++)
        {
            if(rains[i]==0)
            {
                dry.insert(i);
            }
            else
            {
                int lake=rains[i];
                auto it0=rainDay.find(lake);
                if(it0!=rainDay.end())
                {
                    int prev=it0->second;
                    auto it=dry.lower_bound(prev);
                    if(it==dry.end())
                    {
                        return {};
                    }
                    int d=*it;
                    ans[d]=lake;
                    dry.erase(it);
                }
                rainDay[lake]=i;
                ans[i]=-1;
            }
        }
        return ans;
    }
};
