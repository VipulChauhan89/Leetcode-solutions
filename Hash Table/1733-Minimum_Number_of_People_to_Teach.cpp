class Solution {
public:
    int minimumTeachings(int n,vector<vector<int>> &languages,vector<vector<int>> &friendships)
    {
        unordered_set<int> need;
        for(auto &i:friendships)
        {
            int u=i[0]-1,v=i[1]-1;
            bool ok=false;
            for(auto x:languages[u])
            {
                for(auto y: languages[v])
                {
                    if(x==y)
                    {
                        ok=true;
                        break;
                    }
                }
                if(ok)
                {
                    break;
                }
            }
            if(!ok)
            {
                need.insert(u);
                need.insert(v);
            }
        }
        int ans=languages.size()+1;
        for(int i=1;i<=n;i++)
        {
            int count=0;
            for(auto v:need)
            {
                bool found=false;
                for(auto c:languages[v])
                {
                    if(c==i)
                    {
                        found=true;
                        break;
                    }
                }
                if(!found)
                {
                    count++;
                }
            }
            ans=min(ans,count);
        }
        return ans;
    }
};
