class Solution {
public:
    int maximumInvitations(vector<int> &favorite) 
    {
        int n=favorite.size(),cycle=0,chain=0;
        vector<bool> visited(n);
        vector<int> inDegree(n),chainLength(n);
        queue<int> q;
        for(auto &i:favorite)
        {
            inDegree[i]++;
        }
        for(int i=0;i<n;i++)
        {
            if(!inDegree[i])
            {
                q.push(i);
            }
        }
        while(!q.empty())
        {
            int u=q.front();
            q.pop();
            visited[u]=true;
            int nn=favorite[u];
            chainLength[nn]=max(chainLength[nn],chainLength[u]+1);
            if(--inDegree[nn]==0)
            {
                q.push(nn);
            }
        }
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                int cycleLength=0,u=i;
                while(!visited[u])
                {
                    visited[u]=true;
                    u=favorite[u];
                    cycleLength++;
                }
                if(cycleLength==2)
                {
                    chain+=2+chainLength[i]+chainLength[favorite[i]];
                }
                else
                {
                    cycle=max(cycle,cycleLength);
                }
            }
        }
        return max(cycle,chain);
    }
};
