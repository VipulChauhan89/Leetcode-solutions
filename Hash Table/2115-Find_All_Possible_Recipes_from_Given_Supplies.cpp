class Solution {
public:
    vector<string> findAllRecipes(vector<string> &recipes,vector<vector<string>> &ingredients,vector<string> &supplies) 
    {
        int n=recipes.size();
        unordered_set<string> s(supplies.begin(),supplies.end());
        vector<int> d(n,0);
        unordered_map<string,vector<int>> m;
        queue<int> q;
        vector<string> ans;
        for(int i=0;i<n;i++)
        {
            for(auto &j:ingredients[i])
            {
                if(!s.count(j))
                {
                    m[j].push_back(i);
                    d[i]++;
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            if(d[i]==0)
            {
                q.push(i);
            }
        }
        while(!q.empty())
        {
            int i=q.front();
            q.pop();
            auto j=recipes[i];
            ans.push_back(j);
            for(auto &k:m[j])
            {
                if(--d[k]==0)
                {
                    q.push(k);
                }
            }
        }
        return ans;
    }
};
