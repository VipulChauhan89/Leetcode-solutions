class Solution {
public:
    vector<vector<int>> adj;
    int ans=0;
    int dfs(string& s,int i)
    {
        vector<int> a;
        for(auto j:adj[i])
        {
            if(s[j]!=s[i])
            {
                a.push_back(1+dfs(s,j));
            }
            else
            {
                ans=max(ans,dfs(s,j));
            }
        }
        sort(a.begin(),a.end(),greater<int>());
        if(a.size()>=2)
        {
            ans=max(ans,a[0]+a[1]);
        }
        if(a.size()==0)
        {
            return 0;
        }
        return a[0];
    }
    int longestPath(vector<int>& p,string s) 
    {
        adj=vector<vector<int>>(s.size());
        for(int i=1;i<p.size();i++)
        {
            adj[p[i]].push_back(i);
        }
        int temp=dfs(s,0);
        ans=max(ans,temp);
        return ans+1;
    }
};
