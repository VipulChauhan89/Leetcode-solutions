class Solution {
public:
    vector<int> longestRepeating(string s,string queryCharacters,vector<int> &queryIndices)
    {
        int n=s.size();
        set<int> starts;
        multiset<int> lens;
        for(auto run:s | views::chunk_by(equal_to{}))
        {
            starts.insert(int(run.begin()-s.begin()));
            lens.insert(int(run.size()));
        }
        starts.insert(n);
        auto add_break=[&](int p)
        {
            auto it=starts.lower_bound(p);
            int l=*prev(it),r=*it;
            starts.insert(p);
            lens.erase(lens.find(r-l));
            lens.insert(p-l);
            lens.insert(r-p);
        };
        auto remove_break=[&](int p)
        {
            auto it=starts.find(p);
            int l=*prev(it),r=*next(it);
            starts.erase(it);
            lens.erase(lens.find(p-l));
            lens.erase(lens.find(r-p));
            lens.insert(r-l);
        };
        vector<int> result;
        result.reserve(queryIndices.size());
        for(auto [i,c]:views::zip(queryIndices,queryCharacters))
        {
            char old=s[i];
            if(c!=old)
            {
                for(auto [p,nb]:{pair{i,i-1},pair{i+1,i+1}})
                {
                    if(0<=nb && nb<n)
                    {
                        if(s[nb]==old)
                        {
                            add_break(p);
                        }
                        else if(s[nb]==c)
                        {
                            remove_break(p);
                        }
                    }
                }
                s[i]=c;
            }
            result.push_back(*lens.rbegin());
        }
        return result;
    }
};
