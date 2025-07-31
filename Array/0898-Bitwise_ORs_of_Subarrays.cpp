class Solution {
public:
    int subarrayBitwiseORs(vector<int> &arr)
    {
        unordered_set<int> ans,current;
        for(auto &i:arr)
        {
            unordered_set<int> next;
            next.insert(i);
            for(auto &j:current)
            {
                next.insert(i|j);
            }
            ans.insert(next.begin(),next.end());
            current=next;
        }
        return ans.size();
    }
};
