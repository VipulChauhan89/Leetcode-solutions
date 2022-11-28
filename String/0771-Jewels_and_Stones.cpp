class Solution {
public:
    int numJewelsInStones(string jewels, string stones) 
    {
        int count=0;
        unordered_map<char,int> m;
        for(auto c:stones)
        {
            m[c]++;
        }
        for(auto c:jewels)
        {
            count+=m[c];
        }
        return count;
    }
};
