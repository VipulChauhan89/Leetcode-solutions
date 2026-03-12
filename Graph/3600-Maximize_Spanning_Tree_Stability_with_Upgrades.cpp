struct DSU
{
    vector<int> parent,size;
    int components;
    DSU(int n)
    {
        parent.resize(n);
        size.resize(n,1);
        iota(parent.begin(),parent.end(),0);
        components=n;
    }
    int findParent(int node)
    {
        if(parent[node]==node)
        {
            return node;
        }
        return parent[node]=findParent(parent[node]);
    }
    bool unionSet(int a,int b)
    {
        int rootA=findParent(a);
        int rootB=findParent(b);
        if(rootA!=rootB)
        {
            if(size[rootA]<size[rootB])
            {
                swap(rootA,rootB);
            }
            parent[rootB]=rootA;
            size[rootA]+=size[rootB];
            components--;
            return true;
        }
        return false;
    }
};

class Solution {
public:
    int maxStability(int n,vector<vector<int>> &edges,int k)
    {
        DSU connectCheck(n);
        for(auto &edge:edges)
        {
            connectCheck.unionSet(edge[0],edge[1]);
        }
        if(connectCheck.components>1)
        {
            return -1;
        }
        DSU baseDSU(n);
        int minFixedWeight=2e9;
        vector<pair<int,pair<int,int>>> optionalEdges;
        for(auto &edge:edges)
        {
            if(edge[3]==1)
            {
                minFixedWeight=min(minFixedWeight,edge[2]);
                if(!baseDSU.unionSet(edge[0],edge[1]))
                {
                    return -1;
                }
            } 
            else
            {
                optionalEdges.push_back({edge[2],{edge[0],edge[1]}});
            }
        }
        auto isValid=[&](int threshold,DSU tempDSU)
        {

            for(auto &edge:optionalEdges)
            {
                if(edge.first>=threshold)
                {
                    tempDSU.unionSet(edge.second.first,edge.second.second);
                }
            }
            int usedEdges=0;
            for(auto &edge:optionalEdges)
            {
                if(edge.first<threshold && 2*edge.first>=threshold)
                {
                    if(tempDSU.unionSet(edge.second.first,edge.second.second))
                    {
                        usedEdges++;
                    }
                }
            }
            return tempDSU.components==1 && usedEdges<=k;
        };
        int low=-1;
        int high=min(200000,minFixedWeight)+1;
        while(high-low>1)
        {
            int mid=low+(high-low)/2;
            if(isValid(mid,baseDSU))
            {
                low=mid;
            }
            else
            {
                high=mid;
            }
        }
        return low;
    }
};
