class Solution {
public:
    void helper(int i,int n,vector<int> &score,int currScore,vector<int> &freq,vector<string> &words,int &maxScore) 
    {
        if(i==n) 
        {
            maxScore=max(maxScore,currScore);
            return;
        }
        helper(i+1,n,score,currScore,freq,words,maxScore);
        vector<int> oldFreq(freq.begin(),freq.end());
        bool flag=false;
        int wordScore=0;
        for(char &c:words[i]) 
        {
            if(freq[c-'a']==0) 
            {
                flag=true;
                break;
            }
            else 
            {
                freq[c-'a']--;
                wordScore+=score[c-'a'];
            }
        }
        if(!flag)
        {
            helper(i+1,n,score,currScore+wordScore,freq,words,maxScore);
        } 
        for(int i=0;i<26;i++) 
        {
            freq[i]=oldFreq[i];
        }
    }
    int maxScoreWords(vector<string> &words,vector<char> &letters,vector<int> &score) 
    {
        vector<int> freq(26,0);
        for(char &c:letters) 
        {
            freq[c-'a']++;
        }
        int maxScore=0;
        helper(0,words.size(),score,0,freq,words,maxScore);
        return maxScore;
    }
};
