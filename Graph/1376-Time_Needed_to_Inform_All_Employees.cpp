class Solution {
public:
    int dfs(vector<int> graph[],int src,vector<int> &informTime)
    {
        int k=informTime[src],mx=0;
        for(auto i:graph[src])
        {
            mx=max(mx,dfs(graph,i,informTime));
        }
        return k+mx;
    }
    int numOfMinutes(int n,int headID,vector<int> &manager,vector<int> &informTime) 
    {
        vector<int> graph[n];
        for(int i=0;i<n;i++)
        {
            if(manager[i]==-1)
            {
                continue;
            }
            graph[manager[i]].push_back(i);
        }
        return dfs(graph,headID,informTime);
    }
};
