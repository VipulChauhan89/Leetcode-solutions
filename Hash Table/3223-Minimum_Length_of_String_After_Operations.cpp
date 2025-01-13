class Solution {
public:
    int minimumLength(string s) 
    {
        int ans=0;
        unordered_map<char,int> m;
        for(auto &i:s)
        {
            m[i]++;
        }
        for(auto &i:m)
        {
            ans+=((i.second%2==0)?2:1);
        }
        return ans;
    }
};
