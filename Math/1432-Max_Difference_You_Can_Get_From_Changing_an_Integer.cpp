class Solution {
public:
    int maxDiff(int num)
    {
        string s=to_string(num),mx_s=s,mn_s=s;
        for(auto &i:s)
        {
            if(i!='9')
            {
                for (auto &j:mx_s) 
                {
                    if(j==i)
                    {
                        j='9';
                    }
                }
                break;
            }
        }
        if(s[0]!='1')
        {
            char to_replace=s[0];
            for(auto &i:mn_s)
            {
                if(i==to_replace)
                {
                    i='1';
                }
            }
        }
        else 
        {
            for(int i=1;i<s.size();i++)
            {
                if(s[i]!='0' && s[i]!='1')
                {
                    char to_replace=s[i];
                    for(auto &i:mn_s)
                    {
                        if(i==to_replace)
                        {
                            i='0';
                        }
                    }
                    break;
                }
            }
        }
        return stoi(mx_s)-stoi(mn_s);
    }
};
