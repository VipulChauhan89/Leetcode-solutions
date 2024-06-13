class Solution {
public:
    bool isPalindrome(string s) 
    {
        int l=0,r=s.length()-1;
        while(l<r)
        {
            if(!isalpha(s[l]) && !isdigit(s[l]))
            {
                l++;
                continue;
            }
            if(!isalpha(s[r]) && !isdigit(s[r]))
            {
                r--;
                continue;
            }
            if(tolower(s[l++])!=tolower(s[r--]))
            {
                return false;
            }
        }   
        return true;
    }
};
