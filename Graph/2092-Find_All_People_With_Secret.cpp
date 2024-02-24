class Solution {
public:
    void dfs(int u,int time,vector<pair<int,int>> list[],vector<int> &min)
    {
        for(auto [v,w]:list[u])
        {
            if(time<=w && min[v]>w)
            {
                min[v]=w;
                dfs(v,w,list,min);
            }
        }
    }
    vector<int> findAllPeople(int n,vector<vector<int>> &meetings,int firstPerson) 
    {
        vector<pair<int,int>> list[n];
        vector<int> min(n,INT_MAX),ans;
        meetings.push_back({0,firstPerson,0});
        min[0]=0;
        for(int i=0;i<meetings.size();i++)
        {
            list[meetings[i][0]].push_back({meetings[i][1],meetings[i][2]});
            list[meetings[i][1]].push_back({meetings[i][0],meetings[i][2]});
        }
        dfs(0,0,list,min);
        for(int i=0;i<n;i++)
        {
            if(min[i]!=INT_MAX)
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
