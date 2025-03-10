class Solution {
public:
    bool isVowel(char c) 
    {
        return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
    }
    long long atLeastK(string &word,int k) 
    {
        int n=word.size(),c=0,l=0;
        long long ans=0;
        unordered_map<char,int> m;
        for(int i=0;i<n;i++) 
        {
            if(isVowel(word[i])) 
            {
                m[word[i]]++;
            } 
            else 
            {
                c++;
            }
            while(m.size()==5 && c>=k) 
            {
                ans+=n-i;
                if(isVowel(word[l])) 
                {
                    m[word[l]]--;
                    if(m[word[l]]==0) 
                    {
                        m.erase(word[l]);
                    }
                } 
                else 
                {
                    c--;
                }
                l++;
            }
        }
        return ans;
    }
    long long countOfSubstrings(string word,int k) 
    {
        return atLeastK(word,k)-atLeastK(word,k+1);
    }
};
