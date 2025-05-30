class Solution {
public:
    void dfs(int current,int distance,vector<int> &edges,vector<int> &distances) 
    {
        while(current!=-1 && distances[current]==-1) 
        {
            distances[current]=distance++;
            current=edges[current];
        }
    }
    int closestMeetingNode(vector<int> &edges,int node1,int node2) 
    {
        int ans=-1,Min_Of_Max=INT_MAX,n=edges.size();
        vector<int> dist1(n,-1),dist2(n,-1);
        dfs(node1,0,edges,dist1);
        dfs(node2,0,edges,dist2);
        for(int i=0;i<n;i++) 
        {
            if(dist1[i]>=0 && dist2[i]>=0) 
            {
                int maxDist=max(dist1[i],dist2[i]);
                if(maxDist<Min_Of_Max) 
                {
                    Min_Of_Max=maxDist;
                    ans=i;
                }
            }
        }
        return ans;
    }
};
