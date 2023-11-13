class Solution {
public:
    bool isVowel(char c)
    {
        if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
        {
            return true;
        }
        return false;
    }
    string sortVowels(string s) 
    {
        string ans="";
        vector<char> v;
        for(auto i:s)
        {
            char c=tolower(i);
            if(isVowel(c))
            {
                v.push_back(i);
            }
        }
        sort(v.begin(),v.end());
        int j=0;
        for(auto i:s)
        {
            char c=tolower(i);
            if(isVowel(c))
            {
                ans+=v[j++];
                continue;
            }
            ans+=i;
        }
        return ans;
    }
};
