class Solution {
public:
    vector<int> queryResults(int limit,vector<vector<int>> &queries) 
    {
        unordered_map<int,int> m,color;
        vector<int> ans;
        for(auto &i:queries)
        {
            int ball=i[0],ballc=i[1];
            if(m.contains(ball)) 
            {
                int old_color=m[ball];
                color[old_color]--;
                if(color[old_color]==0) 
                {
                   color.erase(old_color);
                }
            }
            m[ball]=ballc;
            color[ballc]++;
            ans.push_back(static_cast<int>(color.size()));
        }
        return ans;
    }
};
