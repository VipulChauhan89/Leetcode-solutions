class Solution {
public:
    vector<int> findMinHeightTrees(int n,vector<vector<int>> &edges) 
    {
        if(n==1)
        {
            return {0};
        }
        unordered_map<int,vector<int>> g;
        vector<int> deg(n,0);
        for(auto &i:edges)
        {
            int u=i[0],v=i[1];
            g[u].push_back(v);
            g[v].push_back(u);
            deg[u]++;
            deg[v]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++)
        {
            if(deg[i]==1)
            {
                q.push(i);
            }
        }
        int r=n;
        while(r>2)
        {
            int size=q.size();
            r-=size;
            for(int i=0;i<size;i++)
            {
                int l=q.front();
                q.pop();
                for(auto j:g[l])
                {
                    deg[j]--;
                    if(deg[j]==1)
                    {
                        q.push(j);
                    }
                }
            }
        }
        vector<int> ans;
        while(!q.empty())
        {
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
    }
};
