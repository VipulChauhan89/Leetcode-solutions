class Solution {
public:
    bool isVowel(char c)
    {
        return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u');
    }
    string maskVowels(string &s)
    {
        string r=s;
        for(auto &c:r)
        {
            if(isVowel(c))
            {
                c='a';
            }
        }
        return r;
    }
    string toLowerStr(string &s)
    {
        string r=s;
        for(char &c:r)
        {
            c=tolower((unsigned char)c);
        }
        return r;
    }
    vector<string> spellchecker(vector<string> &wordlist,vector<string> &queries)
    {
        unordered_set<string> exact(wordlist.begin(),wordlist.end());
        unordered_map<string,string> lowerMap,vowelMap;
        lowerMap.reserve(wordlist.size()*2);
        vowelMap.reserve(wordlist.size()*2);
        for(auto &w:wordlist)
        {
            string wl=toLowerStr(w),masked=maskVowels(wl);
            if(!lowerMap.count(wl))
            {
                lowerMap[wl]=w;
            }
            if(!vowelMap.count(masked))
            {
                vowelMap[masked]=w;
            }
        }
        vector<string> ans;
        ans.reserve(queries.size());
        for(auto &q:queries)
        {
            if(exact.count(q))
            {
                ans.push_back(q);
                continue;
            }
            string ql=toLowerStr(q);
            auto it=lowerMap.find(ql);
            if(it!=lowerMap.end())
            {
                ans.push_back(it->second);
                continue;
            }
            string qMasked=maskVowels(ql);
            auto it2=vowelMap.find(qMasked);
            if(it2!=vowelMap.end())
            {
                ans.push_back(it2->second);
            }
            else
            {
                ans.push_back("");
            }
        }
        return ans;
    }
};
