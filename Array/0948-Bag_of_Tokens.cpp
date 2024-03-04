class Solution {
public:
    int bagOfTokensScore(vector<int> &tokens,int power) 
    {
        sort(tokens.begin(),tokens.end());
        int n=tokens.size(),score=0,mxScore=0,l=0,r=tokens.size()-1;
        while(l<=r)
        {
            if(power>=tokens[l])
            {
                power-=tokens[l];
                score+=1;
                l++;
                mxScore=max(mxScore,score);
            }
            else if(score>0)
            {
                power+=tokens[r];
                score-=1;
                r--;
            }
            else
            {
                break;
            }
        }
        return mxScore;
    }
};
