class Solution {
public:
    vector<int> countOfPairs(int n, int x, int y) {
        vector<int> ans(n,0);
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                ans[min({abs(j-i),abs(x-i)+abs(y-j)+1,abs(y-i)+abs(x-j)+1})-1]+=2;
            }
        }
        return ans;
    }
};
