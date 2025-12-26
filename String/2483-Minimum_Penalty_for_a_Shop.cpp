class Solution {
public:
    int bestClosingTime(string customers)
    {
        int bestTime=0,minPenalty=0,prefix=0,n=customers.length();
        for(int i=0;i<n;i++)
        {
            prefix+=customers[i]=='Y'?-1:1;
            if(prefix<minPenalty)
            {
                bestTime=i+1;
                minPenalty=prefix;
            }
        }
        return bestTime;
    }
};
