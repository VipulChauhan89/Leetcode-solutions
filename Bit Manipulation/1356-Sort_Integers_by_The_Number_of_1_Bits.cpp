class Solution {
public:
    static int countSetBits(int n)
    {
        int count=0;
        while(n)
        {
            n&=(n-1);
            count++;
        }
        return count;
    }
    static bool comp(int a,int b)
    {
        int bitCountA=countSetBits(a);
        int bitCountB=countSetBits(b);
        if(bitCountA==bitCountB)
        {
            return a<b;
        }
        return bitCountA<bitCountB;
    }
    vector<int> sortByBits(vector<int> &arr) 
    {
        sort(arr.begin(),arr.end(),comp);
        return arr;
    }
};
