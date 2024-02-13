class Solution {
public:
    bool palindrome(string s)
    {
        int l=0,r=s.length()-1;
        while(l<=r)
        {
            if(s[l++]!=s[r--])
            {
                return false;
            }
        }
        return true;
    }
    string firstPalindrome(vector<string> &words) 
    {
        string ans="";
        for(auto &i:words)
        {
            if(palindrome(i))
            {
                ans=i;
                break;
            }
        }
        return ans;
    }
};
