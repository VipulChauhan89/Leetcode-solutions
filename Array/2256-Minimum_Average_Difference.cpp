class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) 
    {
        int n=nums.size();
        if(n==1)
        {
            return 0;
        }
        vector<long long> v;
        pair<int,int> p({INT_MAX,0});
        v.push_back(nums[0]);
        for(int i=1;i<n;i++)
        {
            v.push_back(v[i-1]+nums[i]);
        }
        for(int i=1;i<n;i++)
        {
            int a=abs((v[i-1]/i)-(v[n-1]-v[i-1])/(n-i));
            if(p.first>a)
            {
                p.first=a;
                p.second=i-1;
            }
        }
        if(p.first>abs(v[n-1]/n))
        {
            p.first=abs(v[n-1]/n);
            p.second=n-1;
        }
        return p.second;
    }
};
