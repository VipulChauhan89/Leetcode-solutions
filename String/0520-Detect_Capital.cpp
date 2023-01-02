class Solution {
public:
    bool detectCapitalUse(string word) 
    {   
        int c1=0,c2=0;
        for(auto i:word)
        {
            c2++;
            c1+=(i>=65 && i<=90)?1:0;
        }   
        return ((c1==0 || c2-c1==0) || (c1==1 && (word[0]>=65 && word[0]<=90)))?true:false;
    }
};
