class Solution {
public:
    int remove(string &s,char fi,char se,int fp,int sp)
    {
        int ans=0;
        vector<char> st1,st2;
        for(auto &i:s)
        {
            if(!st1.empty() && st1.back()==fi && i==se)
            {
                st1.pop_back();
                ans+=fp;
            }
            else
            {
                st1.push_back(i);
            }
        }
        for(auto &i:st1)
        {
            if(!st2.empty() && st2.back()==se && i==fi)
            {
                st2.pop_back();
                ans+=sp;
            }
            else
            {
                st2.push_back(i);
            }
        }
        return ans;
    }
    int maximumGain(string s,int x,int y)
    {
        if(x<y)
        {
            return remove(s,'b','a',y,x);
        }
        else
        {
            return remove(s,'a','b',x,y);
        }
    }
};
