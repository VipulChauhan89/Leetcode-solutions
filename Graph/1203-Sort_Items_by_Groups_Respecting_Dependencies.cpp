class Solution{
public:
    bool topoSort(vector<int> adj[],vector<int> &topo,vector<int> &deg)
    {
        queue<int> q;
        for(int i=0;i<deg.size();i++)
        {
            if(deg[i]==0)
            {
                q.push(i);
            }
        }
        while(!q.empty())
        {
            int curr=q.front();
            q.pop();
            topo.push_back(curr);
            for(int v:adj[curr])
            {
                deg[v]--;
                if(deg[v]==0)
                {
                    q.push(v);
                }
            }
        }
        return topo.size()==deg.size();
    }
    vector<int> sortItems(int n,int m,vector<int> &group,vector<vector<int>> &beforeItems) 
    {
        int k=m;
        for(auto &it:group)
        {
            if(it==-1)
            {
                it=k++;
            }
        }
        vector<int> ItemDeg(n,0),ItemAdj[n],GroupDeg(k,0),GroupAdj[k],fixedItems,fixedGroups,ans;
        for(int v=0;v<n;v++)
        {
            for(int u:beforeItems[v])
            {
                ItemAdj[u].push_back(v);
                ItemDeg[v]++;
                if(group[u]!=group[v])
                {
                    GroupAdj[group[u]].push_back(group[v]);
                    GroupDeg[group[v]]++;
                }
            }
        }
        bool its=topoSort(ItemAdj,fixedItems,ItemDeg),grp=topoSort(GroupAdj,fixedGroups,GroupDeg);
        if(its==0 || grp==0)
        {
            return {};
        } 
        unordered_map<int,vector<int>> mp;
        for(int it:fixedItems)
        {
            mp[group[it]].push_back(it);
        }
        for(int grp:fixedGroups)
        {
            vector<int> temp=mp[grp];
            for(auto it:temp)
            {
                ans.push_back(it);
            }
        }
        return ans;
    }
};
