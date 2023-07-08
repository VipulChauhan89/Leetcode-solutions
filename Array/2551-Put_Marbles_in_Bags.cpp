class Solution {
public:
    long long putMarbles(vector<int> &weights,int k) 
    {
        int n=weights.size();
        if(k==1 || n==k)
        {
            return 0;
        }
        vector<int> v;
        for(int i=0;i<n-1;i++)
        {
            v.push_back(weights[i]+weights[i+1]);
        }
        sort(v.begin(),v.end());
        long long mn=0,mx=0;
        for(int i=0;i<k-1;i++)
        {
            mn+=v[i];
            mx+=v[n-2-i];
        }
        return mx-mn;
    }
};
