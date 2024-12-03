class Solution {
public:
    string addSpaces(string s, vector<int> &spaces) 
    {
        int start=0;
        string ans="";
        for(auto i:spaces)
        {
            ans+=s.substr(start,i-start)+" ";
            start=i;
        }
        ans+=s.substr(start);
        return ans;
    }
};
