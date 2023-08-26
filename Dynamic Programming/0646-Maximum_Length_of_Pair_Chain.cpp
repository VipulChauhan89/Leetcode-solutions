class Solution {
public:
    int findLongestChain(vector<vector<int>> &pairs) 
    {
        sort(pairs.begin(),pairs.end(),[](const vector<int> &a,const vector<int> &b) 
        {
            return a[1]<b[1];
        });
        int cur=INT_MIN,ans=0;
        for(auto &i:pairs) 
        {
            if(cur<i[0]) 
            {
                cur=i[1];
                ans++;
            }
        }   
        return ans;
    }
};
