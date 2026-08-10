class Solution {
public:
    vector<int> memo;
    bool winnerSquareGame(int n)
    {
        memo=vector<int>(n+1,0);
        return canWin(n);
    }
    bool canWin(int n)
    {
        if(n==0)
        {
            return false;
        }
        if(memo[n]!=0)
        {
            return memo[n]==1;
        }
        bool win=false;
        for(int i=1;i*i<=n;i++)
        {
            if(!canWin(n-i*i))
            {
                win=true;
                break;
            }
        }
        memo[n]=win?1:2;
        return win;
    }
};
