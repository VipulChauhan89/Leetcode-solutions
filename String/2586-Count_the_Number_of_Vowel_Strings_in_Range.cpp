class Solution {
public:
    bool isVowel(char s)
    {
        return (s=='a' || s=='e' || s=='i' || s=='o' || s=='u')?true:false;
    }
    int vowelStrings(vector<string>& words, int left, int right) 
    {
        int count=0;
        for(int i=left;i<=right;i++)
        {
            string s=words[i];
            if(isVowel(s[0]) && isVowel(s[s.length()-1]))
            {
                count++;
            }
        }
        return count;
    }
};
