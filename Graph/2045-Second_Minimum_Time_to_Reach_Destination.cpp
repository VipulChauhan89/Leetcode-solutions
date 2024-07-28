class Solution {
public:
    int secondMinimum(int n,vector<vector<int>> &edges,int time,int change) 
    {
        vector<vector<int>> graph(n+1);
        for(auto &i:edges) 
        {
            graph[i[0]].push_back(i[1]);
            graph[i[1]].push_back(i[0]);
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minHeap;
        vector<int> dist1(n+1,INT_MAX),dist2(n+1,INT_MAX),freq(n+1,0);
        minHeap.push({0,1});
        while(!minHeap.empty()) 
        {
            auto [timeTaken,node]=minHeap.top();
            minHeap.pop();
            freq[node]++;
            if(freq[node]==2 && node==n) 
            {
                return timeTaken;
            }
            for(auto i:graph[node]) 
            {
                int newTimeTaken=timeTaken;
                if((newTimeTaken/change)%2) 
                {
                    newTimeTaken=change*(newTimeTaken/change+1)+time;
                } 
                else 
                {
                    newTimeTaken=newTimeTaken+time;
                }
                if(dist1[i]>newTimeTaken) 
                {
                    dist2[i]=dist1[i];
                    dist1[i]=newTimeTaken;
                    minHeap.push({newTimeTaken,i});
                } 
                else if(dist2[i]>newTimeTaken && dist1[i]!=newTimeTaken) 
                {
                    dist2[i]=newTimeTaken;
                    minHeap.push({newTimeTaken,i});
                }
            }
        }
        return 0;
    }
};
