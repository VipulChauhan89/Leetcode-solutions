class Solution {
public:
    
    bool cal(string &s,int idx,int cnt,unordered_map<string,int> &m)
    {
        if(idx==s.size())
        {
            return cnt>1;   
        }
        string tmp="";
        for(int i=idx;i<s.size();i++)
        {
            tmp+=s[i];
            if(m.find(tmp)!=m.end())
            {
                if(cal(s,i+1,cnt+1,m))
                {
                    return true;
                }
            }
        }
        return false;
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_map<string,int> m;
        for(auto i:words)
        {
            m[i]++;
        }
        vector<string> ans;
        for(auto i:words)
        {
            if(cal(i,0,0,m))
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
