class Solution {
public:
    bool bipartiteDfs(int u,vector<int> A[],vector<int> &color)
    {
        
        for(auto &edges:A[u])
        {
            if(color[edges]==-1)
            {
                color[edges]=1-color[u];
                if(!bipartiteDfs(edges,A,color)) 
                {
                    return false;
                }
            }
            else if(color[edges]==color[u])
            {
                return false;
            } 
        }
        return true;
    }
    bool possibleBipartition(int n,vector<vector<int>>& dislikes) 
    {
        vector<int>A[n+1];
        vector<int>color(n+1,-1);
        for(int i=0;i<dislikes.size();i++)
        {
            A[dislikes[i][0]].push_back(dislikes[i][1]);
            A[dislikes[i][1]].push_back(dislikes[i][0]);
        }
        for(int i=1;i<=n;i++)
        {
            if(color[i]==-1)
            {
                if(!bipartiteDfs(i,A,color))
                {
                    return false;
                } 
            }
        }
        return true;
    }
};
