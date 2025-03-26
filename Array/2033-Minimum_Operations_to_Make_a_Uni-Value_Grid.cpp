class Solution {
public:
    int minOperations(vector<vector<int>> &grid,int x) 
    {
        vector<int> v;
        for(auto &i:grid) 
        {
            for(auto &j:i) 
            {
                v.push_back(j);
            }
        }
        int mod=v[0]%x;
        for(auto &i:v) 
        {
            if(i%x!=mod)
            {
                return -1;
            } 
        }
        sort(v.begin(),v.end());
        int median=v[v.size()/2],op=0;
        for(auto &i:v) 
        {
            op+=abs(i-median)/x;
        }
        return op;
    }
};
