class Solution {
public:
    vector<string> uncommonFromSentences(string s1,string s2) 
    {
        unordered_map<string,int> m;
        string temp;
        stringstream ss(s1+" "+s2);
        while(ss>>temp)
        {
            m[temp]++;
        }
        vector<string> ans;
        for(auto &i:m)
        {
            if(i.second==1)
            {
                ans.push_back(i.first);
            }
        }
        return ans;
    }
};
