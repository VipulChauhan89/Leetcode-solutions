class Solution {
public:
    vector<int> closestPrimes(int left,int right) 
    {
        int prev=-1,diff=INT_MAX;
        vector<int> ans={-1,-1};
        vector<bool> prime(right+1,true);
        prime[0]=prime[1]=false;
        for(int i=2;i*i<=right;i++)
        {
            if(prime[i])
            {
                for(int j=i*i;j<=right;j+=i)
                {
                    prime[j]=false;
                }
            }
        }
        for(int i=left;i<=right;i++)
        {
            if(prime[i])
            {
                if(prev!=-1)
                {
                    if(i-prev<diff)
                    {
                        ans={prev,i};
                        diff=i-prev;
                    }
                }
                prev=i;
            }
        }
        return ans;
    }
};
