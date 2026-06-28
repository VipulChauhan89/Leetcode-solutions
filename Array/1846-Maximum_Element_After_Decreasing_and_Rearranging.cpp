class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int> &arr)
    {
        vector<int> freq(1e5+5);
        int n=arr.size(),ans=1;
        for(auto &x:arr)
        {
            freq[min(x,n)]++;
        }
        for(int i=2;i<=n;i++)
        {
            ans=min(ans+freq[i],i);
        }
        for(int i=0;i<=n;i++)
        {
            freq[i]=0;
        }
        return ans;
    }
};
