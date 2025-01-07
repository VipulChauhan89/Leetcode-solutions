class Solution {
public:
    vector<string> stringMatching(vector<string> &words) 
    {
        vector<string> ans; 
        unordered_set<string> s;
        int n=words.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(j!=i)
                {
                    if(words[i].find(words[j])!=string::npos && s.find(words[j])==s.end())
                    {
                        s.insert(words[j]);
                        ans.push_back(words[j]);
                    }
                }
            }
        }
        return ans;
    }
};
