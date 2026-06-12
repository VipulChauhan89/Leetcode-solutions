class Solution {
public:
    static constexpr int MOD=1e9+7,LOG=17;
    vector<vector<int>> up,g;
    vector<int> dep;
    void dfs(int u,int p)
    {
        up[0][u]=p;
        for(int v:g[u])
        {
            if(v!=p)
            {
                dep[v]=dep[u]+1,dfs(v,u);
            }
        }
    }
    int lca(int a,int b)
    {
        if(dep[a]<dep[b])
        {
            swap(a,b);
        }
        for(int k=LOG-1;k>=0;k--)
        {
            if(up[k][a]!=-1&&dep[up[k][a]]>=dep[b])
            {
                a=up[k][a];
            }
        }
        if(a==b)
        {
            return a;
        }
        for(int k=LOG-1;k>=0;k--)
        {
            if(up[k][a]!=up[k][b])
            {
                a=up[k][a],b=up[k][b];
            }
        }
        return up[0][a];
    }
    long long modpow(long long a,long long b)
    {
        long long r=1;
        while(b)
        {
            if(b&1)
            {
                r=r*a%MOD;
            }
            a=a*a%MOD;
            b>>=1;
        }
        return r;
    }

    vector<int> assignEdgeWeights(vector<vector<int>>&edges,vector<vector<int>> &q)
    {
        int n=edges.size()+1;
        g.resize(n+1);
        dep.assign(n+1,0);
        up.assign(LOG,vector<int>(n+1,-1));
        for(auto &e:edges)
        {
            g[e[0]].push_back(e[1]),
            g[e[1]].push_back(e[0]);
        }
        dfs(1,-1);
        for(int k=1;k<LOG;k++)
        {
            for(int i=1;i<=n;i++)
            {
                if(up[k-1][i]!=-1)
                {
                    up[k][i]=up[k-1][up[k-1][i]];
                }
            }
        }
        vector<int> ans;
        for(auto &v:q)
        {
            int a=lca(v[0],v[1]);
            int d=dep[v[0]]+dep[v[1]]-2*dep[a];
            ans.push_back(d?modpow(2,d-1):0);
        }
        return ans;
    }
};
