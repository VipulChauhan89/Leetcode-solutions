class Solution {
public:
    void backtrack(string current,int n,vector<string> &happyStrings)
    {
        if(current.size()==n)
        {
            happyStrings.push_back(current);
            return;
        }
        for(auto i:{'a','b','c'})
        {
            if(current.empty() || current.back()!=i)
            {
                backtrack(current+i,n,happyStrings);
            }
        }
    }
    string getHappyString(int n, int k) 
    {
        vector<string> happyStrings;
        backtrack("",n,happyStrings);
        return (k>happyStrings.size()?"":happyStrings[k-1]);   
    }
};
