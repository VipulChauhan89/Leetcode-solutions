class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int> &deck) 
    {
        sort(deck.begin(),deck.end());
        int n=deck.size();
        vector<int> ans(n);
        deque<int> index;
        for(int i=0;i<n;i++)
        {
            index.push_back(i);
        }    
        for(auto i:deck)
        {
            int ix=index.front();
            index.pop_front();
            ans[ix]=i;
            if(!index.empty())
            {
                index.push_back(index.front());
                index.pop_front();
            }
        }
        return ans;
    }
};
