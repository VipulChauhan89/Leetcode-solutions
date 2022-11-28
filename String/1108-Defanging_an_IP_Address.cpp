class Solution {
public:
    string defangIPaddr(string address) 
    {
        string s="";
        for(auto i:address)
        {
            if(i=='.')
            {
                s+="[.]";
            }
            else
            {
                s+=i;
            }
        }
        return s;
    }
};
