class Solution {
public:
    bool judgeCircle(string moves)
    {
        int n=moves.size(),r=0,l=0,u=0,d=0;
        for(char &i:moves)
        {
            if(i=='R')
            {
                r++;
            }
            else if(i=='L')
            {
                l++;
            }
            else if(i=='U')
            {
                u++;
            }
            else
            {
                d++;
            }
        }
        if(r==l && u==d)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};
