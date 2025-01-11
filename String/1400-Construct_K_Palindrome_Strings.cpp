class Solution {
public:
    bool canConstruct(string s,int k) 
    {
        vector<int> a(2,0);
        unordered_map<char,int> m;
        for(auto &i:s)
        {
            m[i]++;
        }
        for(auto &i:m)
        {
            a[i.second%2]++;
        }
        return (a[1]<=k && k<=s.size());
    }
};
