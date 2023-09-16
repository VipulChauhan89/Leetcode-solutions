class Solution {
public:
    vector<int> DIR={0,1,0,-1,0};
    int minimumEffortPath(vector<vector<int>> &heights) 
    {
        int m=heights.size(),n=heights[0].size();
        vector<vector<int>> dist(m,vector<int>(n,INT_MAX));
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> minHeap;
        minHeap.push({0,0,0});
        dist[0][0]=0;
        while(!minHeap.empty()) 
        {
            vector<int> top=minHeap.top();
            minHeap.pop();
            int d=top[0],r=top[1],c=top[2];
            if(d>dist[r][c])
            {
                continue;
            } 
            if(r==m-1 && c==n-1)
            {
                return d;
            } 
            for(int i=0;i<4;i++) 
            {
                int nr=r+DIR[i],nc=c+DIR[i+1];
                if(nr>=0 && nr<m && nc>=0 && nc<n) 
                {
                    int newDist=max(d,abs(heights[nr][nc]-heights[r][c]));
                    if(dist[nr][nc]>newDist) 
                    {
                        dist[nr][nc]=newDist;
                        minHeap.push({dist[nr][nc],nr,nc});
                    }
                }
            }
        }
        return 0;
    }
};
