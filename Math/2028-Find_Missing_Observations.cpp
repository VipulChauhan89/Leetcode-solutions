class Solution {
public:
    vector<int> missingRolls(vector<int> &rolls,int mean,int n) 
    {
        int m=rolls.size();
        long long sum=accumulate(rolls.begin(),rolls.end(),0);
        long long total=(n+m)*mean,diff=total-sum;
        if(diff>6*n || diff<n)
        {
            return {};
        }
        div_t result=div(static_cast<int>(diff),static_cast<int>(n));
        vector<int> ans(n,result.quot);
        fill(ans.begin(),ans.begin()+result.rem,result.quot+1);
        return ans;
    }
};
