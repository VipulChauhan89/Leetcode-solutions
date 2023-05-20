class Solution {
public:
    double dfs(unordered_map<string,unordered_map<string,double>> &G,string s1,string s2,unordered_set<string> &visited)
    {
        if(G[s1].find(s2)!=G[s1].end())
        {
            return G[s1][s2];
        }
        for(auto i:G[s1])
        {
            if(visited.find(i.first)==visited.end())
            {
                visited.insert(i.first);
                double d=dfs(G,i.first,s2,visited);
                if(d)
                {
                    G[s1][s2]=i.second*d;
                    return G[s1][s2];
                }
            }
        }
        return 0;
    }
    vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries) 
    {
        int n=queries.size();
        unordered_map<string,unordered_map<string,double>> G;
        vector<double> ans(n,-1);
        for(int i=0;i<equations.size();i++)
        {
            G[equations[i][0]][equations[i][1]]=values[i];
            G[equations[i][1]][equations[i][0]]=(double)1/values[i];
        }
        for(int i=0;i<queries.size();i++)
        {
            unordered_set<string> visited;
            double value=dfs(G,queries[i][0],queries[i][1],visited);
            if(value)
            {
                ans[i]=value;
            }
        }
        return ans;
    }
};
