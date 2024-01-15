class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>> & matches) 
    {
        unordered_map<int,int> m;
        for(auto &i:matches)
        {
            m[i[1]]++;
        }
        vector<int> zero,one;
        for(auto &i:matches)
        {
            int w=i[0],l=i[1];
            if(m.find(w)==m.end())
            {
                zero.push_back(w);
                m[w]=2;
            }
            if(m[l]==1)
            {
                one.push_back(l);
            }
        }
        sort(zero.begin(),zero.end());
        sort(one.begin(),one.end());
        return {zero,one};
    }
};
