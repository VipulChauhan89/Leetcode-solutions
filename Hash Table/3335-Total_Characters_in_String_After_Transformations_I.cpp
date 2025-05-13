class Solution {
public:
    int lengthAfterTransformations(string s,int t) 
    {
        int mod=1e9+7,sum=0;
        unordered_map<int,int> m;
        for(auto &i:s)
        {
            m[i-'a']++;
        }
        while(t--)
        {
            int element=m[25];
            for(int i=25;i>0;i--)
            {
                m[i]=m[i-1];
            }
            m[0]=(element)%mod;
            m[1]=(m[1]+element)%mod;
        }
        for(auto &i:m)
        {
            sum=(sum+i.second)%mod;
        }
        return sum;
    }
};
