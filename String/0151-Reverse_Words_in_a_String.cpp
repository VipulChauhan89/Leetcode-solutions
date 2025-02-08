class Solution {
public:
    string reverseWords(string s) 
    {
        string ans="";
        stringstream ss(s);
        while(ss>>s)
        {
            ans=s+" "+ans;
        }
        ans.pop_back();
        return ans;
    }
};
