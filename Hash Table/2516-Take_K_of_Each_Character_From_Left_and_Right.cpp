class Solution {
public:
    int takeCharacters(string s,int k) 
    {
        vector<int> count(3,0);
        for(auto c:s)
        {
            count[c-'a']++;
        }
        if(*min_element(count.begin(),count.end())<k)
        {
            return -1;
        }
        int ans=INT_MAX,l=0;
        for(int i=0;i<s.length();i++)
        {
            count[s[i]-'a']--;
            while(*min_element(count.begin(),count.end())<k)
            {
                count[s[l]-'a']++;
                l++;
            }
            ans=min(ans,static_cast<int>(s.length())-(i-l+1));
        }
        return ans;
    }
};
