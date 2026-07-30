class Solution {
public:
    int minimumPushes(string word)
    {
        int n=word.length(),ans=0;
        for(int i=0;i<n;i++)
        {
            ans+=(i/8)+1;
        }
        return ans;
    }
};
