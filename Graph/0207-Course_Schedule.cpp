class Solution {
public:
    bool cycle(vector<vector<int>> &v,int src,vector<bool> &rst,vector<bool> &visited)
    {
        visited[src]=true;
        rst[src]=true;
        for(auto i:v[src])
        {
            if(!visited[i] && cycle(v,i,rst,visited))
            {
                return true;
            }
            else if(rst[i])
            {
                return true;
            }
        }
        return rst[src]=false;
    }
    bool canFinish(int numCourses,vector<vector<int>> &prerequisites) 
    {
        vector<vector<int>> G(numCourses);
        vector<bool> visited(numCourses),rst(numCourses);
        stack<int> s;
        for(auto &i:prerequisites)
        {
            G[i[1]].push_back(i[0]);
        }
        for(int i=0;i<numCourses;i++)
        {
            if(!visited[i])
            {
                if(cycle(G,i,rst,visited))
                {
                    return false;
                }
            }
        }
        return true;
    }
};
