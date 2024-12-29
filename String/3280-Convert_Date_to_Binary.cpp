class Solution {
public:
    string intToBinaryString(int n) 
    {
        string ans="";
        while(n)
        {
            if(n&1)
            {
                ans="1"+ans;
            }
            else
            {
                ans="0"+ans;
            }
            n>>=1;
        }
        return ans;
    }
    string convertDateToBinary(string date) 
    {
        int year=stoi(date.substr(0,4));
        int month=stoi(date.substr(5,6));
        int dt=stoi(date.substr(8));
        return intToBinaryString(year)+"-"+intToBinaryString(month)+"-"+intToBinaryString(dt);
    }
};
