class Solution {
public:
    int largestPathValue(string colors,vector<vector<int>> &edges) 
    {
        int n=colors.size();
        vector<vector<int>> graph(n),dp(n,vector<int>(26,0));
        vector<int> indegree(n,0);
        queue<int> q;
        for(auto &i:edges) 
        {
            graph[i[0]].push_back(i[1]);
            indegree[i[1]]++;
        }
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            } 
            dp[i][colors[i]-'a']=1;
        }
        int processed=0,maxColorValue=0;
        while(!q.empty()) 
        {
            int node=q.front();
            q.pop();
            processed++;
            for(auto &i:graph[node]) 
            {
                for(int c=0;c<26;c++) 
                {
                    int extra=(colors[i]-'a'==c)?1:0;
                    dp[i][c]=max(dp[i][c],dp[node][c]+extra);
                }
                if(--indegree[i]==0) 
                {
                    q.push(i);
                }
            }
            maxColorValue=max(maxColorValue,*max_element(dp[node].begin(),dp[node].end()));
        }
        return (processed==n)?maxColorValue:-1;
    }
};
