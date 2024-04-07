class Solution {
public:
    bool checkValidString(string s) 
    {
        int l=0,h=0;
        for(auto i:s) 
        {
            l+=(i=='(')?1:-1;
            h+=(i!=')')?1:-1;
            if(h<0)
            {
                return false;
            } 
            l=max(l,0);
        }
        return l==0;
    }
};
