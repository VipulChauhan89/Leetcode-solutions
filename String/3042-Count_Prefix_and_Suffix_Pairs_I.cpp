class Solution {
public:
    int countPrefixSuffixPairs(vector<string> &words) 
    {
        int n=words.size(),count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i>j)
                {
                    int len1=words[i].length(),len2=words[j].length();
                    if(len1>=len2)
                    {
                        if(words[i].substr(0,len2)==words[j] && words[i].substr(len1-len2)==words[j])
                        {
                            count++;
                        }
                    }
                }
            }
        }
        return count;
    }
};
