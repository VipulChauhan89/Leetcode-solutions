class Solution {
public:
    int minOperations(vector<vector<int>> &grid,int x)
    {
        int n=grid.size(),m=grid[0].size(),mn=grid[0][0],mx=mn;
        int N =n*m;
        vector<int> freq(10001,0);
        for(auto &row:grid)
        {
            for(auto val:row)
            {
                if((val-grid[0][0])%x!=0)
                {
                    return -1;
                }
                freq[val]++;
                mn=min(mn,val);
                mx=max(mx,val);
            }
        }
        int target=(N+1)/2;
        int acc=0,median=mn;
        for(int i=mn;i<=mx;i+=x)
        {
            acc+=freq[i];
            if(acc>=target)
            {
                median=i;
                break;
            }
        }
        int ops=0;
        for(int i=mn;i<=mx;i+=x)
        {
            ops+=abs(i-median)/x*freq[i];
        }
        return ops;
    }
};
