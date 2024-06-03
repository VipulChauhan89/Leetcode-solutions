class Solution {
public:
    int appendCharacters(string s,string t) 
    {
        int si=0,ti=0,sl=s.length(),tl=t.length();
        while(si<sl && ti<tl)
        {
            if(s[si]==t[ti])
            {
                ti++;
            }
            si++;
        }
        return tl-ti;
    }
};
