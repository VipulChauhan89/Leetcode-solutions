class Solution {
public:
    long dfs(int n,int p,int &k,vector<int> &values,int &ans,unordered_map<int,vector<int>> &m)
    {
        long sub=values[n];
        for(auto &i:m[n])
        {
            if(i!=p)
            {
                sub+=dfs(i,n,k,values,ans,m);
            }
        }
        if(sub%k==0)
        {
            ans+=1;
            sub=0;
        }
        return sub;
    }
    int maxKDivisibleComponents(int n,vector<vector<int>> &edges,vector<int> &values,int k) 
    {
        int ans=0;
        unordered_map<int,vector<int>> m;
        for(auto &i:edges)
        {
            m[i[0]].push_back(i[1]);
            m[i[1]].push_back(i[0]);
        }
        dfs(0,-1,k,values,ans,m);
        return ans;
    }
};
