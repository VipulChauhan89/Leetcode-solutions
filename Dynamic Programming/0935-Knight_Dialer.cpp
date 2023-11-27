class Solution {
public:
    static const int mod=1e9+7;
    vector<vector<int>> moves={{4,6},{8,6},{7,9},{4,8},{3,9,0},{},{0,1,7},{2,6},{1,3},{2,4}};
    int cache[5001][10];
    int knightDialer(int n) 
    {
        vector<int> nextNumbers={0,1,2,3,4,5,6,7,8,9};
        return knightDialer(n,nextNumbers);
    }
    int knightDialer(int remaining,vector<int> &nextNumbers)
    {
        if(remaining==1)
        {
            return nextNumbers.size();
        }
        int count=0;
        for(auto i:nextNumbers)
        {
            int cur=cache[remaining][i];
            if(cur==0)
            {
                cur=knightDialer(remaining-1,moves[i]);
                cache[remaining][i]=cur;
            }
            count+=cur;
            count%=mod;
        }
        return count;
    }
};
