class Solution {
public:
    string reorganizeString(string s) 
    {
        unordered_map<char,int> m;
        for(auto i:s)
        {
            m[i]++;
        }   
        vector<char> sorted;
        for(auto &i:m)
        {
            sorted.push_back(i.first);
        }
        sort(sorted.begin(),sorted.end(),[&](char a, char b) {
            return m[a] > m[b];
        });
        if(m[sorted[0]]>(s.length()+1)/2)
        {
            return "";
        }
        string s1(s.length(),' ');
        int i=0;
        for(auto c:sorted)
        {
            for(int j=0;j<m[c];j++)
            {
                if(i>=s.length())
                {
                    i=1;
                }
                s1[i]=c;
                i+=2;
            }
        }
        return s1;
    }
};
