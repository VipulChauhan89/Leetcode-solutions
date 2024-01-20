class Solution {
public:
    int sumSubarrayMins(vector<int> &arr) 
    {
        int n=arr.size();
        vector<long long> dp(n,0);
        vector<int> s;
        const int MOD=1e9+7;
        long long sum=0;
        for(int i=0;i<n;i++)
        {
            while(s.size()!=0 && arr[i]<=arr[s.back()])
            {
                s.pop_back();
            }
            if(s.size()==0)
            {
                dp[i]=(arr[i]*(i+1))%MOD;
            }
            else
            {
                int e=s.back();
                dp[i]=(dp[e]+(arr[i]*(i-e))%MOD)%MOD;
            }
            s.push_back(i);
            sum=(sum+dp[i])%MOD;
        }
        return sum;
    }
};
