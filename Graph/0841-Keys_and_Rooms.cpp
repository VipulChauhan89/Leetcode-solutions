class Solution {
public:
    void dfs(vector<int> A[],vector<bool> &visited,int u)
    {
        visited[u]=true;
        for(auto it=A[u].begin();it!=A[u].end();it++)
        {
            if(visited[*it]==false)
            {
                dfs(A,visited,*it);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) 
    {
        int n=rooms.size();
        vector<int> A[n];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<rooms[i].size();j++)
            {
                A[i].push_back(rooms[i][j]);
            }
        }
        vector<bool> visited(n,false);
        dfs(A,visited,0);
        for(int i=0;i<n;i++)
        {
            if(visited[i]==false)
            {
                return false;
            }
        }
        return true;
    }
};
