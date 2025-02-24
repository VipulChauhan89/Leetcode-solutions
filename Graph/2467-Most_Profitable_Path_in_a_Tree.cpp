class Solution {
public:
    void findParent(int node,int par,vector<vector<int>> &graph,vector<int> &parent) 
    {
        parent[node]=par;
        for (int neighbor:graph[node]) 
        {
            if(neighbor!=par) 
            {
                findParent(neighbor,node,graph,parent);
            }
        }
    }
    void dfs(int node,int par,int t,int profit,vector<vector<int>> &graph,vector<int> &a,vector<int> &nums,int &ans) 
    {
        int currentProfit=profit+(t<nums[node]?a[node]:(t==nums[node]?a[node]/2:0));
        if(node!=0 && graph[node].size()==1) 
        {
            ans=max(ans,currentProfit);
        }
        for(int neighbor:graph[node]) 
        {
            if(neighbor!=par) 
            {
                dfs(neighbor,node,t+1,currentProfit,graph,a,nums,ans);
            }
        }
    }
    int mostProfitablePath(vector<vector<int>> &edges,int bob,vector<int> &amount) 
    {
        int n=amount.size(),ans=INT_MIN,time=0,x=bob;
        vector<vector<int>> graph(n);
        for(auto &i:edges) 
        {
            graph[i[0]].push_back(i[1]);
            graph[i[1]].push_back(i[0]);
        }
        vector<int> parent(n,-1),nums(n,INT_MAX);
        findParent(0,-1,graph,parent);
        while(x!=-1) 
        {
            nums[x]=time++;
            x=parent[x];
        }
        dfs(0,-1,0,0,graph,amount,nums,ans);
        return ans;
    }
};
