class Solution {
public:
    string mergeAlternately(string word1, string word2) 
    {
        string s;
        int i=0,n=word1.size(),m=word2.size();
        while(i<n && i<m)
        {
            s.push_back(word1[i]);
            s.push_back(word2[i]);
            i++;
        } 
        while(i<n)
        {
            s+=word1[i++];
        }
        while(i<m)
        {
            s+=word2[i++];
        }
        return s;
    }
};
