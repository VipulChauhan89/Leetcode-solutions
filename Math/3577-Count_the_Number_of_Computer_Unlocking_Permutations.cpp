class Solution {
public:
    int countPermutations(vector<int> &complexity)
    {
        int mod=1e9+7,n=complexity.size();
        long long fact=1;
        for(int i=1;i<n;i++)
        {
            if(complexity[i]<=complexity[0])
            {
                return 0;
            }
            fact*=i;
            fact%=mod;
        }
        return fact;
    }
};
