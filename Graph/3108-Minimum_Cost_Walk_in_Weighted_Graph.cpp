class Solution {
public:
    vector<int> p,c;
    int find(int n)
    {
        return p[n]<0?n:p[n]=find(p[n]);
    }
    vector<int> minimumCost(int n,vector<vector<int>> &edges,vector<vector<int>> &query) 
    {
        vector<int> ans;
        p=c=vector<int>(n,-1);
        for(auto &i:edges)
        {
            int u=find(i[0]),v=find(i[1]);
            if(u!=v)
            {
                c[u]&=c[v];
                p[v]=u;
            }
            c[u]&=i[2];
        }
        for(auto &i:query)
        {
            int u=find(i[0]),v=find(i[1]);
            if(i[0]==i[1])
            {
                ans.push_back(0);
            }
            else if(u!=v)
            {
                ans.push_back(-1);
            }
            else
            {
                ans.push_back(c[u]);
            }
        }
        return ans;
    }
};
