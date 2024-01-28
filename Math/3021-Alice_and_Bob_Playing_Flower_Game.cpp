class Solution {
public:
    long long countOdd(int n) 
    {
        return (n+1)/2;
    }
    long long countEven(int n) 
    {
        return n/2;
    }
    long long flowerGame(int n,int m) 
    {
        return countOdd(n)*countEven(m)+countOdd(m)*countEven(n);
    }
};
