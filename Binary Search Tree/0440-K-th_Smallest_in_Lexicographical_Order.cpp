class Solution {
public:
    int countSteps(int n,long long current,long long next) 
    {
        int steps=0;
        while(current<=n) 
        {
            steps+=min(static_cast<long long>(n+1),next)-current;
            current*=10;
            next*=10;
        }
        return steps;
    }
    int findKthNumber(int n,int k) 
    {
        int current=1;
        k--;
        while(k>0) 
        {
            int count=countSteps(n,current,current+1);
            if(count<=k) 
            {
                current++;
                k-=count;
            } 
            else 
            {
                current*=10;
                k--;
            }
        }
        return current;
    }
};
