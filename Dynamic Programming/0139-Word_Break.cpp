class Solution {
public:
    bool solve(string s,vector<string> &wordDict,unordered_map<string, bool> &m)
    {
        if(m.find(s)!=m.end())
        {
            return m[s];
        }
        if(s.length()==0)
        {
            return true;
        }
        for(auto &s1:wordDict)
        {
            size_t index=s.find(s1);
            if(index!=string::npos && index==0)
            {
                string suffix=s.substr(s1.length());
                if(solve(suffix,wordDict,m))
                {
                    m[suffix]=true;
                    return true;
                }
            }
        }
        m[s]=false;
        return false;
    }
    bool wordBreak(string s, vector<string> &wordDict) 
    {
        unordered_map<string,bool> m;
        return solve(s,wordDict,m);
    }
};
