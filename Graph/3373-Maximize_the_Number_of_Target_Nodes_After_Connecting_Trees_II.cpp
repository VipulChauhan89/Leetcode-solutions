class Solution {
public:
    vector<vector<int>> buildList(vector<vector<int>> &edges) 
    {
        vector<vector<int>> G(edges.size()+1);
        for(auto &i:edges) 
        {
            G[i[0]].push_back(i[1]);
            G[i[1]].push_back(i[0]);
        }
        return G;
    }
    void dfsColor(const vector<vector<int>> &G,int u,int parent,vector<int> &color,int &evenCount,int &oddCount) 
    {
        if(color[u]==0)
        {
            evenCount++;
        } 
        else
        {
            oddCount++;
        } 
        for(int i:G[u])
        {
            if(i!=parent) 
            {
                color[i]=color[u]^1;
                dfsColor(G,i,u,color,evenCount,oddCount);
            }
        }
    }
    vector<int> maxTargetNodes(vector<vector<int>> &edges1,vector<vector<int>> &edges2) 
    {
        auto adjA=buildList(edges1),adjB=buildList(edges2);
        int n=adjA.size(),m=adjB.size();
        vector<int> colorA(n,-1),colorB(m,-1);
        int evenA=0,oddA=0,evenB=0,oddB=0;
        colorA[0]=0;
        dfsColor(adjA,0,-1,colorA,evenA,oddA);
        colorB[0]=0;
        dfsColor(adjB,0,-1,colorB,evenB,oddB);
        int maxiB=max(evenB,oddB);
        vector<int> ans(n);
        for(int i=0;i<n;i++)
        {
            ans[i]=(colorA[i]==0?evenA:oddA)+maxiB;
        }
        return ans;
    }
};
