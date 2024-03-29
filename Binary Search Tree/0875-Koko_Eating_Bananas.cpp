class Solution {
public:
    int ok(vector<int>& piles, int m, int h) 
    {
        int hours=0;
        for(auto p:piles) 
        {
            hours+=(p+m-1)/m;
        }
        return hours>h;
    }
    
    int minEatingSpeed(vector<int>& piles,int h) 
    {
        int l=1,r=1e9;
        while(l<r) 
        {
            int m=l+(r-l)/2;
            if(ok(piles,m,h))
            {
                l=m+1;
            } 
            else
            {
                r=m;
            } 
        }
        return l;
    }
};