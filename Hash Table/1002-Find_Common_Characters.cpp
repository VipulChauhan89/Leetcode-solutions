class Solution {
public:
    vector<string> commonChars(vector<string> &words) 
    {
        vector<int> f(26,INT_MAX);
        vector<string> ans;
        for(auto &i:words)
        {
            vector<int> ff(26,0);
            for(auto j:i)
            {
                ff[j-'a']++;
            }
            for(int j=0;j<26;j++)
            {
                f[j]=min(f[j],ff[j]);
            }
        }
        for(int i=0;i<26;i++)
        {
            for(int j=0;j<f[i];j++)
            {
                ans.push_back(string(1,'a'+i));
            }
        }
        return ans;
    }
};
