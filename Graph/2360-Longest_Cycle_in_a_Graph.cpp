class Solution {
public:
    void dfs(int node,vector<int>&edges,vector<bool>&visited,vector<bool>&extra,vector<int>&dist,int &ans,int distance)
    {
        if(node!=-1)
        {
            if(!visited[node])
            {
                visited[node]=true;
                extra[node]=true;
                dist[node]=distance;
                dfs(edges[node],edges,visited,extra,dist,ans,distance+1);
            }
            else if(extra[node])
            {
                ans=max(ans,distance-dist[node]);
            }
            extra[node]=false;
        }
    }
    int longestCycle(vector<int>& edges) 
    {
        int n=edges.size();
        vector<bool>visited(n,false);
        vector<bool>extra(n,false);
        vector<int>dist(n,0);
        int ans=-1;
        for(int i=0;i<edges.size();i++)
        {
            if(!visited[i])
            {
                dfs(i,edges,visited,extra,dist,ans,0);
            }
        }
        return ans;
    }
};
