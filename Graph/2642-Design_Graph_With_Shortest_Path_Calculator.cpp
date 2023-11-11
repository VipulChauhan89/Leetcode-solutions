class Graph {
public:
    vector<vector<pair<int,int>>> A;
    
    Graph(int n,vector<vector<int>> &edges) 
    {
        for(int i=0;i<n;i++)
        {
            vector<pair<int,int>> v;
            A.push_back(v);
        }
        for(int i=0;i<edges.size();i++)
        {
            A[edges[i][0]].push_back({edges[i][1],edges[i][2]});
        }
    }
    
    void addEdge(vector<int> edge) 
    {
        A[edge[0]].push_back({edge[1],edge[2]});
    }
    
    int shortestPath(int node1,int node2) 
    {
        if(node1==node2)
        {
            return 0;
        }
        vector<int> visited(A.size(),INT_MAX);
        queue<int> q;
        q.push(node1);
        visited[node1]=0;
        while(!q.empty())
        {
            int temp=q.front();
            q.pop();
            if(temp==node2)
            {
                continue;
            }
            for(int i=0;i<A[temp].size();i++)
            {
                if(visited[A[temp][i].first]>visited[temp]+A[temp][i].second)
                {
                    visited[A[temp][i].first]=visited[temp]+A[temp][i].second;
                    q.push(A[temp][i].first);
                }
            }
        }
        return visited[node2]==INT_MAX?-1:visited[node2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */
