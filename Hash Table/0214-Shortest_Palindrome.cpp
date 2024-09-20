#include<cstring>
class Solution {
public:
    int knuthMorrisPratt(const string &text,const string &pattern)
    {
        string newString=pattern+"."+text;
        int i=1,k=0,n=newString.length();
        vector<int> ans(n,0);
        while(i<n)
        {
            if(newString[i]==newString[k])
            {
                ans[i++]=++k;
            }
            else
            {
                if(k>0)
                {
                    k=ans[k-1];
                }
                else
                {
                    ans[i++]=0;
                }
            }
        }
        return ans.back();
    }
    string shortestPalindrome(string s) 
    {
        int count=knuthMorrisPratt(string(s.rbegin(), s.rend()), s);
        return string(s.rbegin(),s.rend()).substr(0,s.length()-count)+s;
    }
};
