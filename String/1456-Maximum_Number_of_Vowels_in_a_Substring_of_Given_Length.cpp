class Solution {
public:
    int maxVowels(string s,int k) 
    {
        unordered_set<char> vowels={'a','e','i','o','u'};
        int left=0,right=k,count=0,max_count=0;
        for(int i=left;i<right;i++)
        {
            if(vowels.count(s[i]))
            {
                count++;
            }
        }
        max_count=count;
        while(right<s.size())
        {
            if(vowels.count(s[left++]))
            {
                count--;
            }
            if(vowels.count(s[right++]))
            {
                count++;
            }
            max_count=max(count,max_count);
        }
        return max_count;
    }
};
