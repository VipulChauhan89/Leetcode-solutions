class Solution {
public:
    bool repeatedSubstringPattern(string s) 
    {
        return ((s+s).substr(1,(s+s).size()-2)).find(s)!=string::npos;
    }
};
