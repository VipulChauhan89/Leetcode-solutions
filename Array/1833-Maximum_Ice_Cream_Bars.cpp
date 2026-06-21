class Solution {
public:
    int maxIceCream(vector<int> &costs,int coins)
    {
        vector<int> freq(1e5+1);
        int xMax=0,count=0;
        for(int x:costs)
        {
            freq[x]++;
            xMax=max(xMax,x);
        }
        for(int x=1;x<=xMax;x++)
        {
            const int f=freq[x];
            if(f==0)
            {
                continue;
            }
            int buy=min(coins/x,f);
            if(buy==0)
            {
                break;
            }
            count+=buy;
            coins-=buy*x;
        }
        for(int x:costs)
        {
            freq[x]=0;
        }
        return count;
    }
};
