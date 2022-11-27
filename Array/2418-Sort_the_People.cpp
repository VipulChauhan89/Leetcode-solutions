class Solution {
public:
    static int comp(pair<int,string> a,pair<int,string> b)
    {
        return a.first>b.first;
    }
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) 
    {
        vector<pair<int,string> >v;
        for(int i=0;i<names.size();i++)
        {
            v.push_back({heights[i],names[i]});
        }
        sort(v.begin(),v.end(),comp);
        int j=0;
        for(auto i:v)
        {
            names[j++]=i.second;
        }
        return names;
    }
};
