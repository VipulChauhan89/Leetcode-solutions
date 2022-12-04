class Solution {
public:
    bool isCircularSentence(string sentence) 
    {
        int n=sentence.length();
        if(sentence[0]!=sentence[n-1])
        {
            return false;
        }
        stringstream ss(sentence);
        string word1,word2;
        while(ss>>word1 && ss>>word2)
        {
            if(word1[word1.length()-1]!=word2[0])
            {
                return false;
            }
        }
        return true;
    }
};
