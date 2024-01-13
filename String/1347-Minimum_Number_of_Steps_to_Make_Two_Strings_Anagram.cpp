class Solution {
public:
    int minSteps(string s,string t) 
    {
        vector<int> a(26,0),b(26,0);
        for(auto i:s)
        {
            a[i-'a']++;
        }
        for(auto i:t)
        {
            b[i-'a']++;
        }
        int step=0;
        for(int i=0;i<26;i++)
        {
            step+=abs(a[i]-b[i]);
        }
        return step/2;
    }
};
