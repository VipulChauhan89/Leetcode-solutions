class Solution {
public:
    long long maximumValueSum(vector<int> &nums,int k,vector<vector<int>> &edges) 
    {
        long long sum=0,count=0,node_left=INT_MAX;
        for(long long i:nums) 
        {
            sum+=max(i^k,i);
            count+=(i^k)>i;
            node_left=min(node_left,abs(i-(i^k)));
        }
        return sum-(count%2?node_left:0);
    }
};
