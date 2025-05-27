class Solution {
public:
    int differenceOfSums(int n,int m) 
    {
        vector<int> v(2,0);
        for(int i=1;i<=n;i++)
        {
            v[i%m==0]+=i;
        }
        return v[0]-v[1];
    }
};
