class Solution {
public:
    int sum(int n)
    {
        int s=0;
        while(n!=0)
        {
            s+=n%10;
            n/=10;
        }
        return s;
    }
    int minElement(vector<int> &nums)
    {
        int mn=INT_MAX;
        for(auto &i:nums)
        {
            mn=min(mn,sum(i));
        }
        return mn;
    }
};
