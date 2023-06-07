class Solution {
public:
    int bitCount(long int x)
    {
        int count=0;
        while(x)
        {
            count+=x%2;
            x/=2;
        }
        return count;
    }
    int minFlips(int a,int b,int c) 
    {
        return bitCount(a & ~c)+bitCount(b & ~c)+bitCount(c & ~(a|b));
    }
};
