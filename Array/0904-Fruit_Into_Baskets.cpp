class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int start=0,maxLen=0;
        unordered_map<int,int> m;
        for(int end=0;end<fruits.size();end++)
        {
            m[fruits[end]]++;
            while(m.size()>2)
            {
                m[fruits[start]]--;
                if(m[fruits[start]]==0) {
                    m.erase(fruits[start]);
                }
                start++;
            }

            maxLen=max(maxLen,end-start+1);
        }
        return maxLen;
    }
};
