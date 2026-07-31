class Solution {
public:
    int minimumPushes(string word)
    {
        int ans=0;
        vector<int> freq(26,0);
        for(char c:word)
        {
            freq[c-'a']++;
        }
        sort(freq.begin(),freq.end());
        for(int i=25;i>=0 && freq[i]>0;i--)
        {
            ans += freq[i]*((25-i)/8+1);
        }
        return ans;
    }
};
