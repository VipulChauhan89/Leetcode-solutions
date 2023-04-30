class dsu{
private:
    vector<int>parent;
    int distinct_components;
public:
    dsu(int n)
    {
        distinct_components=n;

        for(int i=0;i<=n;i++)
        {
            parent.push_back(i);
        }
    }
    int find_parent(int u)
    {
        if(parent[u]!=u)
        {
            parent[u]=find_parent(parent[u]);
        }
        return parent[u];
    }
    bool Union(int u,int v)
    {
        if(find_parent(u)==find_parent(v))
        {
            return false;
        }
        parent[find_parent(u)]=v;
        distinct_components--;
        return true;
    }
    bool united()
    {
        return distinct_components==1;
    }
};

class Solution 
{
public:
    int maxNumEdgesToRemove(int n,vector<vector<int>> &edges) 
    {

        sort(edges.begin(),edges.end(),[](auto& it,auto &it2)
        {
            return it[0]>it2[0];
        });

        dsu *bob=new dsu(n);
        dsu *alice=new dsu(n);
        int edges_added=0;

        for(auto &it:edges)
        {
            int type=it[0];
            int u=it[1];
            int v=it[2];

            switch(type)
            {
                case 3 :
                {
                    edges_added+=(bob->Union(u,v) | alice->Union(u,v));
                    break;
                }
                case 2:
                {
                    edges_added+=bob->Union(u,v);
                    break;
                }
                case 1 : 
                {
                    edges_added+=alice->Union(u,v);
                    break;
                }
            }
        }
        return (bob->united() && alice->united()) ? edges.size() - edges_added : -1;
    }
};