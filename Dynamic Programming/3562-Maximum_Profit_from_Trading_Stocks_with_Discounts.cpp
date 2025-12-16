class Solution {
public:
    void dfs(int u,vector<int> &present,vector<int> &future,vector<vector<int>>& tree,vector<vector<vector<int>>> &dp,int budget)
    {
        vector<pair<vector<int>,vector<int>>> childDPs;
        for(auto &i:tree[u])
        {
            dfs(i,present,future,tree,dp,budget);
            childDPs.emplace_back(dp[i][0],dp[i][1]);
        }
        for(int i=0;i<=1;i++)
        {
            int price=i?present[u]/2:present[u],profit=future[u]-price;
            vector<int> curr(budget+1,0),base(budget+1,0);
            for(auto &j:childDPs)
            {
                vector<int> next(budget+1,0);
                for(int k=0;k<=budget;k++)
                {
                    if(base[k]==0 && k!=0)
                    {
                        continue;
                    }
                    for(int l=0;k+l<=budget;l++)
                    {
                        next[k+l]=max(next[k+l],base[k]+j.first[l]);
                    }
                }
                base=move(next);
            }
            for(int j=0;j<=budget;j++)
            {
                curr[j]=max(curr[j],base[j]);
            }
            if(price<=budget)
            {
                vector<int> baseBuy(budget+1,0);
                for(auto &j:childDPs)
                {
                    vector<int> next(budget+1,0);
                    for(int k=0;k<=budget;k++)
                    {
                        if(baseBuy[k]==0 && k!=0)
                        {
                            continue;
                        }
                        for(int l=0;k+l<=budget;l++)
                        {
                            next[k+l]=max(next[k+l],baseBuy[k]+j.second[l]);
                        }
                    }
                    baseBuy=move(next);
                }
                for(int b=price;b<=budget;b++)
                {
                    curr[b]=max(curr[b],baseBuy[b-price]+profit);
                }
            }
            dp[u][i]=move(curr);
        }
    }
    int maxProfit(int n,vector<int> &present,vector<int> &future,vector<vector<int>> &hierarchy,int budget)
    {
        vector<vector<int>> tree(n);
        for(auto &i:hierarchy)
        {
            tree[i[0]-1].push_back(i[1]-1);
        }
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(budget+1,0)));
        dfs(0,present,future,tree,dp,budget);
        int ans=0;
        for(int i=0;i<=budget;i++)
        {
            ans=max(ans,dp[0][0][i]);
        }
        return ans;
    }
};
