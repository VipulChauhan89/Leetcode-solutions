class Solution {
public:
    long long coloredCells(int n) 
    {
        long long N=n;;
        return 4*((N*(N-1))/2)+1;
    }
};
