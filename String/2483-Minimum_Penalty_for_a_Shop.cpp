class Solution {
public:
    int bestClosingTime(string customers) 
    {
        int j=-1,score=0,maxScore=0;
        for(int i=0;i<customers.size();i++) 
        {
            score+=(customers[i]=='Y')?1:-1;
            if(score>maxScore) 
            {
                j=i;
                maxScore=score;
            }
        }
        return j+1;
    }
};
