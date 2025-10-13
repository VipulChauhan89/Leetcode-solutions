class Solution {
public:
    vector<string> removeAnagrams(vector<string> &words)
    {
        int n=words.size();
        vector<unordered_map<char,int>> m(words.size());
        vector<string> ans;
        ans.push_back(words[0]);
        for(int i=0;i<n;i++)
        {
            for(auto &j:words[i])
            {
                m[i][j]++;
            }
        }
        for(int i=1;i<n;i++)
        {
            if(m[i]!=m[i-1])
            {
                ans.push_back(words[i]);
            }
        }
        return ans;
    }
};
