class Solution {
public:
    bool isValid(string word)
    {
        int vowel=0,consonant=0;
        if(word.length()>=3)
        {
            string vow="aeiouAEIOU";
            for(auto &i:word)
            {
                if(isalpha(i))
                {
                    if(vow.find(i)!=string::npos)
                    {
                        vowel++;
                    }
                    else
                    {
                        consonant++;
                    }
                }
                else if(!isdigit(i))
                {
                    return false;
                }
            }
            
        }
        return vowel>=1 && consonant>=1; 
    }
};
