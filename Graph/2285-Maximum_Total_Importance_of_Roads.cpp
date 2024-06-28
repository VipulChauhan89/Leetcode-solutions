class Solution {
public:
    long long maximumImportance(int n,vector<vector<int>> &roads) 
    {
        long long ans=0;
        vector<int> d(n,0),c(n);
        for(auto &i:roads)
        {
            d[i[0]]++;
            d[i[1]]++;
        }   
        for(int i=0;i<n;i++)
        {
            c[i]=i;
        }
        sort(c.begin(),c.end(),[&](int a,int b){
            return d[a]>d[b];
        });
        for(int i=0;i<n;i++)
        {
            ans+=(long long)(n-i)*d[c[i]];
        }
        return ans;
    }
};
