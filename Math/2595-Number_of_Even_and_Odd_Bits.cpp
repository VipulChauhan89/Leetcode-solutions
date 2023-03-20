class Solution {
public:
    string decimalToBinary(int num)
    {
        string Binary;
        while(num)
        {
            Binary+=(num&1)?"1":"0";
            num>>=1;
        }
        return Binary;
    }
    vector<int> evenOddBit(int n) 
    {
        vector<int> a(2,0);
        string s=decimalToBinary(n);
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='1')
            {
                if(i%2==0)
                {
                    a[0]++;
                }
                else
                {
                    a[1]++;
                }
            }
        }
        return a;
    }
};
