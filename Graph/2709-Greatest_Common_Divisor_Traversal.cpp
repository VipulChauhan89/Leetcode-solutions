class Solution {
public:
    unordered_set<int> unique(int n)
    {
        unordered_set<int> f;
        for(int i=2;i<=sqrt(n);i++)
        {
            while(n%i==0)
            {
                f.insert(i);
                n/=i;
            }
        }
        if(n>1)
        {
            f.insert(n);
        }
        return f;
    }
    void dfs(int i,set<int> &visited,vector<vector<int>> &a)
    {
        visited.insert(i);
        for(auto j:a[i])
        {
            if(visited.find(j)==visited.end())
            {
                dfs(j,visited,a);
            }
        }
    }
    bool canTraverseAllPairs(vector<int> &nums) 
    {
        int n=nums.size();
        vector<vector<int>> a(n);
        unordered_map<int,int> ls;
        set<int> visited;
        for(int i=0;i<n;i++)
        {
            unordered_set<int> pf=unique(nums[i]);
            for(auto j:pf)
            {
                if(ls.find(j)!=ls.end())
                {
                    int pi=ls[j];
                    a[pi].push_back(i);
                    a[i].push_back(pi);
                }
                ls[j]=i;
            }
        }
        dfs(0,visited,a);
        return visited.size()==n;
    }
};
