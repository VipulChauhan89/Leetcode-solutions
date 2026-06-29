class Solution {
public:
    int numOfStrings(vector<string> &patterns,string word)
    {
        int ans=0;
        for(auto &s:patterns)
        {
            if(word.find(s)!=string::npos)
            {
                ans++;
            }
        }
        return ans;
    }
};
