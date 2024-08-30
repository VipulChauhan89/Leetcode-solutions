class Solution {
public:
    const int INF=2e9;
    typedef pair<int,int> pi;
    int diajstra(int n,int source,int destination,vector<pair<int,int>> adj[]) 
    {
        vector<int> distance(n,INT_MAX);
        distance[source]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,source});
        while(!pq.empty()) 
        {
            auto [cost,node]=pq.top();pq.pop();
            if(node==destination)
            {
                break;
            } 
            for(auto [ccost,cnode]:adj[node]) 
            {
                if(cost+ccost<distance[cnode]) 
                {
                    distance[cnode]=cost+ccost;
                    pq.push({distance[cnode],cnode});
                }
            }
        }
        return distance[destination];
    }
    vector<vector<int>> modifiedGraphEdges(int n,vector<vector<int>> &edges,int source,int destination,int target) 
    {
        vector<pair<int,int>> adj[n];
        for(auto &e:edges) 
        {
            if(e[2]==-1)
            {
                continue;
            } 
            adj[e[0]].push_back({e[2],e[1]});
            adj[e[1]].push_back({e[2],e[0]});
        }
        int sortedDistance=diajstra(n,source,destination,adj);
        if(sortedDistance<target)
        {
            return {};
        } 
        bool isEqual=sortedDistance==target;
        for(auto &e:edges) 
        {
            if(e[2]!=-1)
            {
                continue;
            } 
            e[2]=isEqual?INF:1;
            adj[e[0]].push_back({e[2],e[1]});
            adj[e[1]].push_back({e[2], e[0]});
            if(!isEqual) 
            {
                int newSortedPath=diajstra(n,source,destination,adj);
                if(newSortedPath<=target) 
                {
                    isEqual=true;
                    e[2]+=target-newSortedPath;
                }
            }
        }  
        if(isEqual)
        {
            return edges;
        } 
        return {};
    }
};
