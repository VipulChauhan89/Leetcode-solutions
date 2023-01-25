class Solution {
public:
    void dfs(int i,int distance,vector<int> &edges,vector<int>& path) 
    {
        while (i!=-1 && path[i]==-1) 
        {
            path[i]=distance++;
            i=edges[i];
        }
    }
    int closestMeetingNode(vector<int>& edges,int node1,int node2) 
    {
        int ans=-1,min_dist=INT_MAX;
        vector<int> m1(edges.size(),-1),m2(edges.size(),-1);
        dfs(node1,0,edges,m1);
        dfs(node2,0,edges,m2);
        for(int i=0;i<edges.size();i++)
        {
            if(min(m1[i],m2[i])>=0 && max(m1[i],m2[i])<min_dist) 
            {
                min_dist=max(m1[i],m2[i]);
                ans=i;
            }
        }
        return ans;
    }
};
