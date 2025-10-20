class Solution {
public:
    int finalValueAfterOperations(vector<string> &operations)
    {
        int ans=0;
        for(auto &i:operations)
        {
            ans+=(i[1]=='+')?1:-1;
        }
        return ans;
    }
};
