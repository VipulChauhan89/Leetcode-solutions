class Solution {
public:
    map<int,vector<int>> adj;
    map<int,int> in,out;
    vector<vector<int>> ans;
    void EulerTour(int u) 
    {
        while(!adj[u].empty()) 
        {
            int v=adj[u].back();
            adj[u].pop_back();
            EulerTour(v);
            ans.push_back({u,v});
        }
    }
    vector<vector<int>> validArrangement(vector<vector<int>> &pairs) 
    {
        for(auto it:pairs) 
        {
            int u=it[0],v=it[1];
            adj[u].push_back(v);
            out[u]++;
            in[v]++;
        }
        int start=-1;
        for(auto [it,_]:adj) 
        {
            if(out[it]>in[it]) 
            {
                start=it;
                break;
            }
        }
        if(start==-1)
        {
            start=pairs[0][0];
        } 
        EulerTour(start);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
