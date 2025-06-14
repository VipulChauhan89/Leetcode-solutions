class Solution {
public:
    int minMaxDifference(int num) 
    {
        string s=to_string(num),mx,mn;
        char ch=0,ch0=s[0];
        for(auto &i:s)
        {
            if(i!='9')
            {
                ch=i; 
                break;
            }
        }
        if(ch) 
        {
            for(auto &i:s)
            {
                mx.push_back(i==ch?'9':i);
            } 
        } 
        else 
        {
            mx=s;
        }
        for(auto &i:s)
        {
            mn.push_back(i==ch0?'0':i);
        } 
        return stoi(mx)-stoi(mn);
    }
};
