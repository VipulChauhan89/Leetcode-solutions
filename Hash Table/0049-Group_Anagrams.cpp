class Solution {
public:
    string Sign(string &s)
    {
        vector<int> m(26,0);
        for(auto i:s)
        {
            m[i-'a']++;
        }
        string ss;
        for(int i=0;i<26;i++)
        {
            if(m[i]!=0)
            {
                ss+=(char)('a'+i)+to_string(m[i]);
            }
        }
        return ss;
    }
    vector<vector<string>> groupAnagrams(vector<string> &strs) 
    {
        vector<vector<string>> ans;
        unordered_map<string,vector<string>> group;
        for(auto i:strs)
        {
            group[Sign(i)].push_back(i);
        }
        for(const auto &i:group)
        {
            ans.push_back(i.second);
        }
        return ans;
    }
};
