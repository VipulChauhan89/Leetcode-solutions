class Solution {
public:
    void dfs(unordered_map<int,vector<int>> &adj,int current,int parent,int depth,int k,int &count) 
    {
        if(depth>k)
        {
            return;
        } 
        count++;
        for(auto &i:adj[current]) 
        {
            if(i!=parent) 
            {
                dfs(adj,i,current,depth+1,k,count);
            }
        }
    }
    int countReachable(unordered_map<int,vector<int>> &adj,int k,int N,int start) 
    {
        int count=0;
        dfs(adj,start,-1,0,k,count);
        return count;
    }
    vector<int> findCount(vector<vector<int>> &edges,int k) 
    {
        int N=edges.size()+1;
        unordered_map<int,vector<int>> adj;
        for(auto &i:edges) 
        {
            int u=i[0],v=i[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> ans(N);
        for(int i=0;i<N;i++) 
        {
            ans[i]=countReachable(adj,k,N,i);
        }
        return ans;
    }
    vector<int> maxTargetNodes(vector<vector<int>> &edges1, vector<vector<int>> &edges2,int k) 
    {
        vector<int> ans1=findCount(edges1,k),ans2=findCount(edges2,k-1);
        int maxFromTree2=*max_element(ans2.begin(),ans2.end());
        for(int i=0;i<ans1.size();i++) 
        {
            ans1[i]+=maxFromTree2;
        }
        return ans1;
    }
};
