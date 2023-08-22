class Solution {
public:
    string convertToTitle(int columnNumber) 
    {
        string s="";
        while(columnNumber)
        {
            columnNumber--;
            s=(char)('A'+columnNumber%26)+s;
            columnNumber/=26;
        }
        return s;
    }
};
