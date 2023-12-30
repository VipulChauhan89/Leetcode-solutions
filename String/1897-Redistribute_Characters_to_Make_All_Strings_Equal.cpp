class Solution {
public:
    bool makeEqual(vector<string> &words) 
    {
        unordered_map<char,int> m;
        for(auto &i:words)
        {
            for(auto j:i)
            {
                m[j]++;
            }
        }
        for(auto &i:m)
        {
            if(i.second%words.size()!=0)
            {
                return false;
            }
        }
        return true;
    }
};
