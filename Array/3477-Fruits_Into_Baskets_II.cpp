class Solution {
public:
    int numOfUnplacedFruits(vector<int> &fruits,vector<int> &baskets)
    {
        int rem=0,n=baskets.size();
        for(auto &i:fruits)
        {
            int var=1;
            for(int j=0;j<n;j++)
            {
                if(i<=baskets[j])
                {
                    baskets[j]=0;
                    var=0;
                    break;
                }
            }
            rem+=var;
        }
        return rem;
    }
};
