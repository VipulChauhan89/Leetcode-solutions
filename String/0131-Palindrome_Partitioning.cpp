class Solution {
public:
    bool palindrome(string s)
    {
        int i=0,j=s.size()-1;
        while(i<j)
        {
            if(s[i++]!=s[j--])
            {
                return false;
            }
        }
        return true;
    }
    void back(string s,vector<vector<string>> &ans,vector<string> &v)
    {
        if(s.size()==0)
        {
            ans.push_back(v);
            return;
        }
        for(int i=0;i<s.size();i++)
        {
            string p=s.substr(0,i+1),l=s.substr(i+1);
            if(palindrome(p))
            {
                v.push_back(p);
                back(l,ans,v);
                v.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) 
    {
        vector<vector<string>> ans;
        vector<string> v;
        back(s,ans,v);
        return ans;
    }
};
