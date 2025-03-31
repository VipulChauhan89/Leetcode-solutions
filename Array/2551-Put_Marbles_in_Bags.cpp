class Solution {
public:
    long long putMarbles(vector<int> &weights,int k) 
    {
        if(k==1)
        {
            return 0;
        }
        int n=weights.size();
        vector<int> s;
        for(int i=1;i<n;i++)
        {
            s.push_back(weights[i-1]+weights[i]);
        }
        sort(s.begin(),s.end());
        long long mn=accumulate(s.begin(),s.begin()+(k-1),0LL),mx=accumulate(s.end()-(k-1),s.end(),0LL);
        return mx-mn;
    }
};
