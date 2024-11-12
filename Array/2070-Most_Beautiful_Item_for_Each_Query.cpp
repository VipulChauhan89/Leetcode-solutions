class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>> &items,vector<int> &queries) 
    {
        int mx=INT_MAX;
        vector<vector<int>> a={{0,0,mx}};
        sort(items.begin(),items.end());
        for(auto &i:items)
        {
            int price=i[0],beauty=i[1];
            if(beauty>a.back()[1])
            {
                a.back()[2]=price;
                a.push_back({price,beauty,mx});
            }
        }
        vector<int> ans;
        for(auto i:queries)
        {
            for(int j=a.size()-1;j>=0;j--)
            {
                if(a[j][0]<=i)
                {
                    ans.push_back(a[j][1]);
                    break;
                }
            }
        }
        return ans;
    }
};
