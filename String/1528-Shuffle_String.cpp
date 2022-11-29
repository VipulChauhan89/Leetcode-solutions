class Solution {
public:
    string restoreString(string s, vector<int>& indices) 
    {
        string s1=s;
        int j=0;
        for(auto i:indices)
        {
            s1[i]=s[j++];
        }
        return s1;
    }
};
