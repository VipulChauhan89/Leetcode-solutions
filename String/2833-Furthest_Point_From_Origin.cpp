class Solution {
public:
    int furthestDistanceFromOrigin(string moves)
    {
        int l=0,r=0,b=0;
        for(auto &i:moves)
        {
            if(i=='L')
            {
                l++;
            }
            else if(i=='R')
            {
                r++;
            }
            else
            {
                b++;
            }
        }
        return abs(l-r)+b;
    }
};
