class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) 
    {
        unordered_map<char,int> m,n;
        for(auto i:ransomNote)
        {
            m[i]++;
        }
        for(auto i:magazine)
        {
            n[i]++;
        }
        for(auto i:ransomNote)
        {
            if(m[i]>n[i])
            {
                return false;
            }
        }
        return true;
    }
};
