class DSU{
public:
    vector<int> rank,parent;
    DSU(int n)
    {
        rank.resize(n);
        parent.resize(n);
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
            rank[i]=0;
        }
    }
    int findParent(int i)
    {
        if(parent[i]==i)
        {
            return i;
        }   
        return parent[i]=findParent(parent[i]);
    }
    void unionByRank(int u,int v)
    {
        u=findParent(u);
        v=findParent(v);
        if(u==v)
        {
            return;
        } 
        if(rank[u]>rank[v])
        {
            parent[v]=u;
        }
        else if(rank[u]<rank[v])
        {
            parent[u]=v;
        }
        else
        {
            parent[v]=u;
            rank[u]++;
        }
        return;
    }
    bool sameComponent(int u,int v)
    {
        return findParent(u)==findParent(v);
    }
};
class Solution {
public:
    static bool comparator(vector<int> &e1,vector<int> &e2)
    {
        return e1[2]<e2[2];
    }
    int kruskal(int n,vector<vector<int>> &edges,int exclude=-1,int include=-1)
    {
        DSU dsu(n+1);
        int mstWt=0,cnt=0;
        if(include!=-1)
        {
            int u=edges[include][0],v=edges[include][1],wt=edges[include][2];
            mstWt+=wt;
            cnt++;
            dsu.unionByRank(u,v);
        }
        for(int i=0;i<edges.size();i++)
        {
            if(i==exclude)
            {
                continue;
            }  
            int u=edges[i][0],v=edges[i][1],wt=edges[i][2];
            if(dsu.sameComponent(u,v))
            {
                continue;
            }  
            mstWt+=wt;
            cnt++;
            dsu.unionByRank(u,v);
        }
        return (cnt==n-1)?mstWt:INT_MAX;
    }

    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n,vector<vector<int>> &edges) 
    {
        int E=edges.size();
        for(int i=0;i<E;i++)
        {
            edges[i].push_back(i);
        }
        sort(edges.begin(),edges.end(),comparator);
        int mstWt=kruskal(n,edges,-1,-1);
        set<int> critical,pcritical;
        for(int i=0;i<E;i++)
        {
            int newMstWt=kruskal(n,edges,i,-1);
            if(newMstWt!=mstWt)
            {
                critical.insert(edges[i][3]);
            }
        }
        for(int i=0;i<E;i++)
        {
            int newMstWt=kruskal(n,edges,-1,i);
            if(newMstWt==mstWt && critical.find(edges[i][3])==critical.end())
            {
                pcritical.insert(edges[i][3]);
            }
        }
        vector<vector<int>> ans(2);
        for(auto it:critical)
        {
            ans[0].push_back(it);
        }
        for(auto it:pcritical)
        {
            ans[1].push_back(it);
        }
        return ans;
    }
};
