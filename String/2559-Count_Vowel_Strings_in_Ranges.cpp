class Solution {
public:
    vector<int> vowelStrings(vector<string> &words,vector<vector<int>> &queries) 
    {
        unordered_set<char> vowels={'a','e','i','o','u'};
        int n=words.size();
        vector<int> ans,prefix(n+1,0);
        for(int i=0;i<n;i++)
        {
            prefix[i+1]=prefix[i];
            if(vowels.count(words[i].front()) && vowels.count(words[i].back()))
            {
                prefix[i+1]++;
            }
        }
        for(auto &i:queries)
        {
            ans.push_back(prefix[i[1]+1]-prefix[i[0]]);
        }
        return ans;
    }
};
