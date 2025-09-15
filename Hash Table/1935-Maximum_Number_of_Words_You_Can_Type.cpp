class Solution {
public:
    int canBeTypedWords(string text,string brokenLetters)
    {
        int n=0;
        unordered_set<char> s;
        stringstream ss(text);
        for(auto &i:brokenLetters)
        {
            s.insert(i);
        }
        string newString;
        while(ss>>newString)
        {
            bool flag=true;
            for(auto &i:newString)
            {
                if(s.count(i))
                {
                    flag=false;
                    break;
                }
            }
            n+=(flag?1:0);
        }
        return n;
    }
};
