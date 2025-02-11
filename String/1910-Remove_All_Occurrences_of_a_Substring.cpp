class Solution {
public:
    string removeOccurrences(string s,string part) 
    {
        int pn=part.size();
        string ans;
        for(auto &i:s)
        {
            ans.push_back(i);
            if(ans.size()>=pn && ans.substr(ans.size()-pn)==part)
            {
                ans.erase(ans.size()-pn,pn);
            }
        }    
        return ans;
    }
};
