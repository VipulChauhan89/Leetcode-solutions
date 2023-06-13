class Solution {
public:
    int equalPairs(vector<vector<int>> &grid) 
    {
        int ans=0;
        map<vector<int>,int> m;
        for(auto &i:grid)
        {
            m[i]++;
        }
        for(int i=0;i<grid[0].size();i++)
        {
            vector<int> A;
            for(int j=0;j<grid.size();j++)
            {
                A.push_back(grid[j][i]);
            }
            ans+=m[A];
        }
        return ans;
    }
};
