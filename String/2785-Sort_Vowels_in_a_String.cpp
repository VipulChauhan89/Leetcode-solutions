class Solution {
public:
    bool isVowel(char c)
    {
        return string("AEIOUaeiou").find(c)!=string::npos;
    }
    string sortVowels(string s)
    {
        vector<char> vowels;
        int v_index=0;
        for(auto &i:s)
        {
            if(isVowel(i))
            {
                vowels.push_back(i);
            }
        }
        sort(vowels.begin(),vowels.end());
        for(int i=0;i<s.size();i++)
        {
            if(isVowel(s[i]))
            {
                s[i]=vowels[v_index++];
            }
        }
        return s;
    }
};