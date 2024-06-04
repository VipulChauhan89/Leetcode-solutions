class Solution {
public:
    int longestPalindrome(string s) 
    {
        int ans=0;
        unordered_map<char,int> m;
        for(auto i:s)
        {
            m[i]++;
        }    
        for(auto &i:m)
        {
            if(i.second>1)
            {
                ans+=i.second-(i.second%2);
            }
        }
        return ans+(ans<s.length()?1:0);
    }
};
