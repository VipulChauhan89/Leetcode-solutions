class Solution {
public:
    long long maxProfit(vector<int> &prices,vector<int> &strategy,int k)
    {
        int n=prices.size();
        long long ap=0,op=0,mp=0,mg=0;
        vector<long long> profit(n);
        for(int i=0;i<n;i++)
        {
            profit[i]=(long long)strategy[i]*prices[i];
            ap+=profit[i];
        }
        int i=0,j=0;
        while(j<n)
        {
            op+=profit[j];
            if(j-i+1>k/2)
            {
                mp+=prices[j];
            }
            if(j-i+1>k)
            {
                op-=profit[i];
                mp-=prices[i+k/2];
                i++;
            }
            if(j-i+1==k)
            {
                mg=max(mg,mp-op);
            }
            j++;
        }
        return ap+mg;
    }
};
