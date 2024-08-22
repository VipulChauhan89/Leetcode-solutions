class Solution {
public:
    int findComplement(int num) 
    {
        int c=0,ans=0;
        while(num!=0)
        {
            int rem=!(num%2);
            ans+=rem*pow(2,c);
            c++;
            num/=2;
        }
        return ans;
    }
};
