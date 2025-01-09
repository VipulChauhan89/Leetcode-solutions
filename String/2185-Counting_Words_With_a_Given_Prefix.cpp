class Solution {
public:
    int prefixCount(vector<string> &words,string pref) 
    {
        int n=words.size(),count=0;
        for(int i=0;i<n;i++)
        {
            if(words[i].find(pref)==0)
            {
                count++;
            }
        }
        return count;
    }
};
