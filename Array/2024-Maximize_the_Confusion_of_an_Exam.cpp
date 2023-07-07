class Solution {
public:
    int maxConsecutiveAnswers(string answerKey,int k) 
    {
        unordered_map<char,int> m;
        int mxfreq=0,i=0;
        for(int j=0;j<answerKey.length();j++)
        {
            char c=answerKey[j];
            m[c]++;
            mxfreq=max(mxfreq,m[c]);
            if(j-i+1>mxfreq+k)
            {
                m[answerKey[i]]--;
                i++;
            }
        }
        return answerKey.length()-i;
    }
};
