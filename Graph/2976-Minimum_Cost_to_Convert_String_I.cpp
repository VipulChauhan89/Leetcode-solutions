class Solution {
public:
    long long minimumCost(string source,string target,vector<char> &original,vector<char> &changed,vector<int> &cost) 
    {
        int infinite=1<<29,n=source.length();
        vector<vector<int>> graph(26,vector<int>(26));
        for(int i=0;i<26;i++)
        {
            fill(graph[i].begin(),graph[i].end(),infinite);
            graph[i][i]=0;
        }
        for(int i=0;i<original.size();i++)
        {
            int x=original[i]-'a',y=changed[i]-'a',z=cost[i];
            graph[x][y]=min(graph[x][y],z);
        }
        for(int k=0;k<26;k++)
        {
            for(int i=0;i<26;i++)
            {
                for(int j=0;j<26;j++)
                {
                    graph[i][j]=min(graph[i][j],graph[i][k]+graph[k][j]);
                }
            }
        }
        long long ans=0;
        for(int i=0;i<n;i++)
        {
            int x=source[i]-'a',y=target[i]-'a';
            if(x!=y)
            {
                if(graph[x][y]>=infinite)
                {
                    return -1;
                }
                ans+=graph[x][y];
            }
        }
        return ans;
    }
};
