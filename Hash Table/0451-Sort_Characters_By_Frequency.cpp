class Solution {
public:
    string frequencySort(string s) 
    {
        unordered_map<char,int> m;
        for(auto i:s)
        {
            m[i]++;
        }
        vector<char> sortedS;
        for(auto &i:m)
        {
            sortedS.push_back(i.first);
        }
        sort(sortedS.begin(),sortedS.end(),[&](char a,char b) {
            return m[a]>m[b];
        });
        string ans="";
        for(auto i:sortedS)
        {
            ans+=string(m[i],i);
        }
        return ans;
    }
};
