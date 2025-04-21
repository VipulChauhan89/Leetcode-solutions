class Solution {
public:
    int numberOfArrays(vector<int> &differences,int lower,int upper) 
    {
        long sum=0,mx=0,mn=0;
        for(auto &i:differences) 
        {
            sum+=i;
            mx=max(mx,sum);
            mn=min(mn,sum);
        }
        return max(0L,upper-lower-mx+mn+1);
    }
};
