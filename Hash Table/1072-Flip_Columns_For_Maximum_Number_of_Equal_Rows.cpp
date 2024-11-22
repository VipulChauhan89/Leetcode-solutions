class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>> &matrix) 
    {
        unordered_map<string,int> m;
        int mx=0;
        for(auto &i:matrix)
        {
            string pattern;
            if(i[0]==0)
            {
                for(auto j:i)
                {
                    pattern+=to_string(j);
                }
            }
            else
            {
                for(auto j:i)
                {
                    pattern+=to_string(j^1);
                }
            }
            m[pattern]++;
            mx=max(mx,m[pattern]);
        }
        return mx;
    }
};
