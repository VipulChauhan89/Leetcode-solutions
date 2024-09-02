class Solution {
public:
    int chalkReplacer(vector<int> &chalk,int k) 
    {
        int n=chalk.size();
        vector<long long> sum(n,chalk[0]);
        for(int i=1;i<n;i++)
        {
            sum[i]=sum[i-1]+chalk[i];
        }
        k%=sum[n-1];
        return upper_bound(sum.begin(),sum.end(),k)-sum.begin();
    }
};
