class Solution {
public:
    static int comp(pair<int,char>a,pair<int,char> b)
    {
        return a.first>b.first;
    }
    string frequencySort(string s) 
    {
        unordered_map<char,int> m;
        vector<pair<int,char> >v;
        string s1="";
        for(auto i:s)
        {
            m[i]++;
        }
        for(auto i:m)
        {
            v.push_back({i.second,i.first});
        }
        sort(v.begin(),v.end(),comp);
        for(auto i:v)
        {
            while(i.first--)
            {
                s1+=i.second;
            }
        }
        return s1;
    }
};
