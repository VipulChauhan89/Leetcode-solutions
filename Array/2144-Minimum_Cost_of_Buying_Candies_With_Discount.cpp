class Solution {
public:
    int minimumCost(vector<int> &cost)
    {
        sort(cost.begin(),cost.end(),greater<int>());
        int ans=0,n=cost.size();
        for(int i=0;i<n;i++)
        {
            if(i%3!=2)
            {
                ans+=cost[i];
            }
        }
        return ans;
    }
};
