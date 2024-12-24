class Solution {
public:
    void dfs(int node,int par,int dis,int &maxi,vector<vector<int>> &adj,int &far)
    {
        if(dis>maxi)
        {
            maxi=dis;
            far=node;
        }
        for(auto it:adj[node])
        {
            if(it!=par)
            {
                dfs(it,node,dis+1,maxi,adj,far);
            }
        }
    }
    int minimumDiameterAfterMerge(vector<vector<int>> &edges1,vector<vector<int>> &edges2) 
    {
        int n=edges1.size()+1,m=edges2.size()+1;
        vector<vector<int>>adj1(n),adj2(m);
        for(auto it:edges1)
        {
            adj1[it[0]].push_back(it[1]);
            adj1[it[1]].push_back(it[0]);
        }
        int maxi1=0,maxi2=0,far=0,far1=0,far2=0;
        dfs(0,-1,0,maxi1,adj1,far);
        maxi1=0;
        dfs(far,-1,0,maxi1,adj1,far1);
        for(auto it:edges2)
        {
            adj2[it[0]].push_back(it[1]);
            adj2[it[1]].push_back(it[0]);
        }
        far=0;
        dfs(0,-1,0,maxi2,adj2,far);
        maxi2=0;
        dfs(far,-1,0,maxi2,adj2,far2);
        int tmp1=(maxi1+1)/2,tmp2=(maxi2+1)/2,mrg=tmp1+tmp2+1;
        return max(maxi1,max(mrg,maxi2));
    }
};
