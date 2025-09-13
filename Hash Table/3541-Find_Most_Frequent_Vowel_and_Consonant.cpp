class Solution {
public:
    int maxFreqSum(string s)
    {
        unordered_map<int,int> m;
        int mxVowel=0,mxConsonant=0;
        for(auto &i:s)
        {
            m[i]++;
            if(i=='a' || i=='e' || i=='i' || i=='o' || i=='u')
            {
                mxVowel=max(mxVowel,m[i]);
            }
            else
            {
                mxConsonant=max(mxConsonant,m[i]);
            }
        }
        return mxVowel+mxConsonant;
    }
};
