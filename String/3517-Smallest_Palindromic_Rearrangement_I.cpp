class Solution {
public:
    string smallestPalindrome(string s)
    {
        int n=s.size(),j=0;
        vector<int> freq(26,0);
        for(int i=0;i<n>>1;i++)
        {
            freq[(s[i]&31)-1]++;
        }            
        for(int i=0;i<26;i++)
        {
            while(freq[i]--)
            {                
                s[j]='a'+i;
                s[n-1-j++]='a'+i;
            }
        }
        return s;
    }
};
