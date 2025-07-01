class Solution {
public:
    int possibleStringCount(string word)
    {
        int n=word.length(),count=n;
        for(int i=1;i<n;i++)
        {
            if(word[i]!=word[i-1])
            {
                count--;
            }
        }
        return count;
    }
};
