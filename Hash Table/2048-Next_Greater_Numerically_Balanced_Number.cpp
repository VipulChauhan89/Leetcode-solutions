class Solution {
public:
    int nextBeautifulNumber(int n)
    {
        n+=1;
        while(1)
        {
            map<int,int> m;
            int num=n;
            while(num>0)
            {
                int d=num%10;
                m[d]++;
                num/=10;
            }
            bool key=true;
            for(auto i:m)
            {
                if(i.first!=i.second)
                {
                    key=false;
                    break;
                }
            }
            if(key)
            {
                return n;
            }
            n++;
        }
        return -1;
    }
};
