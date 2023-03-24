class Solution {
public:
    int count=0;
    void dfs(vector<pair<int,int>>V[],vector<bool> &visited,int i){
        visited[i]=true;
        for(auto it:V[i])
        {
            if(!visited[it.first])
            {
                count+=it.second;
                dfs(V,visited,it.first);
            }
        }
    }
    int minReorder(int n,vector<vector<int>> &connections) 
    {
        vector<pair<int,int>>V[n];
        for(auto it:connections)
        {
            V[it[0]].push_back({it[1],1});
            V[it[1]].push_back({it[0],0});
        }
        vector<bool>visited(n,false);
        dfs(V,visited,0);
        return count;
    }  
};
