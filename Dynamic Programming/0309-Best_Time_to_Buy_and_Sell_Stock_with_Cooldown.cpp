class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int n=prices.size();
        vector<int> front1(2,0);
        vector<int> front2(2,0);
        vector<int> current(2,0);
        for(int i=n-1;i>=0;i--)
        {
            current[1]=max(-prices[i]+front1[0],0+front1[1]);
            current[0]=max(prices[i]+front2[1],0+front1[0]);
            front2=front1;
            front1=current;
        }
        return current[1];
    }
};
