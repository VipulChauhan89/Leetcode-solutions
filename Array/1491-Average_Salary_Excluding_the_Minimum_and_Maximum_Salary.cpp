class Solution {
public:
    double average(vector<int> &salary) 
    {
        double sum=0;
        int n=salary.size()-2,mn=INT_MAX,mx=INT_MIN;
        for(auto i:salary)
        {
            sum+=i;
            mx=max(mx,i);
            mn=min(mn,i);
        }
        sum-=mn+mx;
        return sum/n;
    }
};