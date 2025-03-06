class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>> &grid)
    {
        int mx=0,repeat=0,missing=0;
        unordered_map<int,int> m;
        for(auto &i:grid)
        {
            for(auto &j:i)
            {
                m[j]++;
                mx=max(mx,j);
            }
        }
        for(int i=1;i<=mx;i++)
        {
            if(m.find(i)==m.end())
            {
                missing=i;
            }
            if(m[i]==2)
            {
                repeat=i;
            }
        }
        return {repeat,(missing==0?mx+1:missing)};
    }
};
