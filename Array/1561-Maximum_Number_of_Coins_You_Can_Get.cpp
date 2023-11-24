class Solution {
public:
    int maxCoins(vector<int> &piles) 
    {
        int n=piles.size(),ans=0;
        sort(piles.begin(),piles.end(),greater<int>());
        for(int i=1;i<n-n/3;i+=2)
        {
            ans+=piles[i];
        }
        return ans;
    }
};
