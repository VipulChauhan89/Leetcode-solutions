class Solution {
public:
    bool dfs(int node,unordered_map<int,bool> &safe,vector<vector<int>> &graph) 
    {
        if(safe.find(node)!=safe.end()) 
        {
            return safe[node];
        }    
        safe[node]=false;
        for(int neighbor:graph[node]) 
        {
            if(!dfs(neighbor,safe,graph)) 
            {
                return safe[node];
            }
        }    
        safe[node]=true;
        return safe[node];
    }
    vector<int> eventualSafeNodes(vector<vector<int>> &graph) 
    {
        int n=graph.size();
        unordered_map<int,bool> safe;
        vector<int> ans;
        for(int i=0;i<n;i++) 
        {
            if(dfs(i,safe,graph)) 
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
