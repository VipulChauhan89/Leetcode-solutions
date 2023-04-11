class Solution {
public:
    string removeStars(string s) 
    {
        int n=s.size();
        int cnt=0;
        string k="";
        for(int i=n-1;i>=0;i--)
        {
            if(s[i]=='*')
            cnt++;
            else
            {
                if(cnt>0)
                {
                    cnt--;
                }
                else
                {
                    k+=s[i];
                }
            }
        }
        reverse(k.begin(),k.end());
        return k;
    }
};
