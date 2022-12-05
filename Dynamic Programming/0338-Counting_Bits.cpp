class Solution {
public:
    vector<int> countBits(int n) 
    {
        vector<int> v;
        for(int i=0;i<=n;i++)
        {
            int sum=0,num=i;
            while(num!=0)
            {
                sum+=num%2;
                num/=2;
            }
            v.push_back(sum);
        }
        return v;
    }
};
