class Solution {
public:
    void dfs(vector<int> A[],int u, int p,vector<int> &count,vector<int> &ans) 
    {
        for(auto v:A[u]) 
        {
            if(v==p)
            {
                continue;
            }
            dfs(A,v,u,count,ans);
            count[u]+=count[v];
            ans[u]+=ans[v]+count[v];
        }
        count[u]+=1;
    }
    void dfs2(vector<int> A[],int u,int p,int n,vector<int> &count,vector<int> &ans) 
    {
        for(auto v: A[u]) 
        {
            if(v==p) 
            {
                continue;
            }
            ans[v]=ans[u]-count[v]+n-count[v];
            dfs2(A,v,u,n,count,ans);
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) 
    {
        vector<int> A[n];
        vector<int> ans(n),count(n);
        for(int i=0;i<n-1;i++)
        {
            A[edges[i][0]].push_back(edges[i][1]);
            A[edges[i][1]].push_back(edges[i][0]);
        }
        dfs(A,0,-1,count,ans);
        dfs2(A,0,-1,n,count,ans);
        return ans;
    }
};
