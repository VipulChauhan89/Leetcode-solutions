class Solution {
public:
    string customSortString(string order,string s) 
    {
        unordered_map<int,int> m;
        string ans="";
        for(auto i:s)
        {
            m[i]++;
        }
        for(auto i:order)
        {
            if(m.find(i)!=m.end())
            {
                ans.append(m[i],i);
                m.erase(i);
            }
        }
        for(auto &i:m)
        {
            ans.append(i.second,i.first);
        }
        return ans;
    }
};
