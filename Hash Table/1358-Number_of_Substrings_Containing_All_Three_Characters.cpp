class Solution {
public:
    int numberOfSubstrings(string s) {
        int c=0,l=0;
        unordered_map<char,int> m={{'a',0},{'b',0},{'c',0}};
        for(int i=0;i<s.length();i++) 
        {
            m[s[i]]++;
            while(m['a']>0 && m['b']>0 && m['c']>0) 
            {
                c+=s.length()-i;
                m[s[l]]--;
                l++;
            }
        }
        return c;
    }
};
