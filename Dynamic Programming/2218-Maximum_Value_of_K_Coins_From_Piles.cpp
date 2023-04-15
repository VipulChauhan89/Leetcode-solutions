class Solution {
public:
    vector<vector<int>> dp;
    int maxValueOfCoins(vector<vector<int>> &piles,int k) 
    {
        dp.resize(piles.size(),vector<int>(k+1,0));        
        return  calculateMaxCoinValue(0,piles,k);
    }
    int calculateMaxCoinValue(int pileIndex,vector<vector<int>> &piles,int coinsLeft)
    {
        if(pileIndex>=piles.size())
        {
            return 0;
        }
        if(dp[pileIndex][coinsLeft]!=0)
        {
            return dp[pileIndex][coinsLeft];
        }
        int maxCoinValue=0,sum=0;
        maxCoinValue=max(maxCoinValue,calculateMaxCoinValue(pileIndex+1,piles,coinsLeft));
        for(int i=0;i<piles[pileIndex].size();i++)
        {
            sum+=piles[pileIndex][i];
            if(coinsLeft-(i+1)>=0)
            {
                maxCoinValue=max(maxCoinValue,sum+calculateMaxCoinValue(pileIndex+1,piles,coinsLeft-(i+1)));
            }
        }
        return dp[pileIndex][coinsLeft]=maxCoinValue;
    }
};
